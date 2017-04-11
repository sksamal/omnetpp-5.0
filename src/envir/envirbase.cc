//==========================================================================
//  ENVIRBASE.CC - part of
//                     OMNeT++/OMNEST
//             Discrete System Simulation in C++
//
//  Author: Andras Varga
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include <cstdio>
#include <cassert>
#include <csignal>
#include <fstream>
#include <set>
#include <algorithm>
#include "common/stringtokenizer.h"
#include "common/fnamelisttokenizer.h"
#include "common/stringutil.h"
#include "common/enumstr.h"
#include "common/opp_ctype.h"
#include "common/stringtokenizer.h"
#include "common/fileglobber.h"
#include "common/unitconversion.h"
#include "common/commonutil.h"
#include "common/ver.h"
#include "common/fileutil.h"  // splitFileName
#include "omnetpp/ccoroutine.h"
#include "omnetpp/csimulation.h"
#include "omnetpp/cscheduler.h"
#include "omnetpp/cfutureeventset.h"
#include "omnetpp/cpar.h"
#include "omnetpp/cproperties.h"
#include "omnetpp/cproperty.h"
#include "omnetpp/crng.h"
#include "omnetpp/ccanvas.h"
#include "omnetpp/cmodule.h"
#include "omnetpp/cmessage.h"
#include "omnetpp/ccomponenttype.h"
#include "omnetpp/cxmlelement.h"
#include "omnetpp/chistogram.h"
#include "omnetpp/cobjectfactory.h"
#include "omnetpp/checkandcast.h"
#include "omnetpp/cfingerprint.h"
#include "omnetpp/cconfigoption.h"
#include "omnetpp/cnedmathfunction.h"
#include "omnetpp/cnedfunction.h"
#include "omnetpp/regmacros.h"
#include "omnetpp/simtime.h"
#include "omnetpp/cresultrecorder.h"
#include "omnetpp/platdep/timeutil.h"
#include "omnetpp/platdep/platmisc.h"
#include "sim/resultfilters.h"
#include "args.h"
#include "envirbase.h"
#include "envirutils.h"
#include "appreg.h"
#include "cxmldoccache.h"
#include "statisticparser.h"

#ifdef WITH_PARSIM
#include "omnetpp/cparsimcomm.h"
#include "sim/parsim/cparsimpartition.h"
#include "sim/parsim/cparsimsynchr.h"
#include "sim/parsim/creceivedexception.h"
#endif

#ifdef USE_PORTABLE_COROUTINES  /* coroutine stacks reside in main stack area */

# define TOTAL_STACK_SIZE    (2*1024*1024)
# define MAIN_STACK_SIZE     (128*1024)  // Tkenv needs more than 64K

#else /* nonportable coroutines, stacks are allocated on heap */

# define TOTAL_STACK_SIZE    0  // dummy value
# define MAIN_STACK_SIZE     0  // dummy value

#endif

#if defined _WIN32
#define DEFAULT_DEBUGGER_COMMAND    "start gdb --pid=%u"
#elif defined __APPLE__
#define DEFAULT_DEBUGGER_COMMAND    "XTerm -e 'gdb --pid=%u' &"  // looks like we cannot launch XCode like that
#else /* Linux, *BSD and other: assume Nemiver is available and installed */
#define DEFAULT_DEBUGGER_COMMAND    "nemiver --attach=%u &"
#endif

#ifdef NDEBUG
#define CHECKSIGNALS_DEFAULT        "false"
#else
#define CHECKSIGNALS_DEFAULT        "true"
#endif

using namespace omnetpp::common;

namespace omnetpp {
namespace envir {

using std::ostream;

#define CREATE_BY_CLASSNAME(var, classname, baseclass, description) \
    baseclass *var ## _tmp = (baseclass *)createOne(classname); \
    var = dynamic_cast<baseclass *>(var ## _tmp); \
    if (!var) \
        throw cRuntimeError("Class \"%s\" is not subclassed from " #baseclass, (const char *)classname);

Register_GlobalConfigOptionU(CFGID_TOTAL_STACK, "total-stack", "B", nullptr, "Specifies the maximum memory for `activity()` simple module stacks. You need to increase this value if you get a \"Cannot allocate coroutine stack\" error.");
Register_GlobalConfigOption(CFGID_PARALLEL_SIMULATION, "parallel-simulation", CFG_BOOL, "false", "Enables parallel distributed simulation.");
Register_GlobalConfigOption(CFGID_SCHEDULER_CLASS, "scheduler-class", CFG_STRING, "omnetpp::cSequentialScheduler", "Part of the Envir plugin mechanism: selects the scheduler class. This plugin interface allows for implementing real-time, hardware-in-the-loop, distributed and distributed parallel simulation. The class has to implement the `cScheduler` interface.");
Register_GlobalConfigOption(CFGID_PARSIM_COMMUNICATIONS_CLASS, "parsim-communications-class", CFG_STRING, "omnetpp::cFileCommunications", "If `parallel-simulation=true`, it selects the class that implements communication between partitions. The class must implement the `cParsimCommunications` interface.");
Register_GlobalConfigOption(CFGID_PARSIM_SYNCHRONIZATION_CLASS, "parsim-synchronization-class", CFG_STRING, "omnetpp::cNullMessageProtocol", "If `parallel-simulation=true`, it selects the parallel simulation algorithm. The class must implement the `cParsimSynchronizer` interface.");
Register_GlobalConfigOption(CFGID_EVENTLOGMANAGER_CLASS, "eventlogmanager-class", CFG_STRING, "omnetpp::envir::EventlogFileManager", "Part of the Envir plugin mechanism: selects the eventlog manager class to be used to record data. The class has to implement the `cIEventlogManager` interface.");
Register_GlobalConfigOption(CFGID_OUTPUTVECTORMANAGER_CLASS, "outputvectormanager-class", CFG_STRING, "omnetpp::envir::cIndexedFileOutputVectorManager", "Part of the Envir plugin mechanism: selects the output vector manager class to be used to record data from output vectors. The class has to implement the `cIOutputVectorManager` interface.");
Register_GlobalConfigOption(CFGID_OUTPUTSCALARMANAGER_CLASS, "outputscalarmanager-class", CFG_STRING, "omnetpp::envir::cFileOutputScalarManager", "Part of the Envir plugin mechanism: selects the output scalar manager class to be used to record data passed to recordScalar(). The class has to implement the `cIOutputScalarManager` interface.");
Register_GlobalConfigOption(CFGID_SNAPSHOTMANAGER_CLASS, "snapshotmanager-class", CFG_STRING, "omnetpp::envir::cFileSnapshotManager", "Part of the Envir plugin mechanism: selects the class to handle streams to which snapshot() writes its output. The class has to implement the `cISnapshotManager` interface.");
Register_GlobalConfigOption(CFGID_FUTUREEVENTSET_CLASS, "futureeventset-class", CFG_STRING, "omnetpp::cEventHeap", "Part of the Envir plugin mechanism: selects the class for storing the future events in the simulation. The class has to implement the `cFutureEventSet` interface.");
Register_GlobalConfigOption(CFGID_IMAGE_PATH, "image-path", CFG_PATH, "", "A semicolon-separated list of directories that contain module icons and other resources. This list with be concatenated with `OMNETPP_IMAGE_PATH`.");
Register_GlobalConfigOption(CFGID_FNAME_APPEND_HOST, "fname-append-host", CFG_BOOL, nullptr, "Turning it on will cause the host name and process Id to be appended to the names of output files (e.g. omnetpp.vec, omnetpp.sca). This is especially useful with distributed simulation. The default value is true if parallel simulation is enabled, false otherwise.");
Register_GlobalConfigOption(CFGID_DEBUG_ON_ERRORS, "debug-on-errors", CFG_BOOL, "false", "When set to true, runtime errors will cause the simulation program to break into the C++ debugger (if the simulation is running under one, or just-in-time debugging is activated). Once in the debugger, you can view the stack trace or examine variables.");
Register_GlobalConfigOption(CFGID_PRINT_UNDISPOSED, "print-undisposed", CFG_BOOL, "true", "Whether to report objects left (that is, not deallocated by simple module destructors) after network cleanup.");
Register_GlobalConfigOption(CFGID_SIMTIME_SCALE, "simtime-scale", CFG_INT, "-12", "DEPRECATED in favor of simtime-resolution. Sets the scale exponent, and thus the resolution of time for the 64-bit fixed-point simulation time representation. Accepted values are -18..0; for example, -6 selects microsecond resolution. -12 means picosecond resolution, with a maximum simtime of ~110 days.");
Register_GlobalConfigOption(CFGID_SIMTIME_RESOLUTION, "simtime-resolution", CFG_CUSTOM, "ps", "Sets the resolution for the 64-bit fixed-point simulation time representation. Accepted values are: second-or-smaller time units (`s`, `ms`, `us`, `ns`, `ps`, `fs` or as), power-of-ten multiples of such units (e.g. 100ms), and base-10 scale exponents in the -18..0 range. The maximum representable simulation time depends on the resolution. The default is picosecond resolution, which offers a range of ~110 days.");
Register_GlobalConfigOption(CFGID_NED_PATH, "ned-path", CFG_PATH, "", "A semicolon-separated list of directories. The directories will be regarded as roots of the NED package hierarchy, and all NED files will be loaded from their subdirectory trees. This option is normally left empty, as the OMNeT++ IDE sets the NED path automatically, and for simulations started outside the IDE it is more convenient to specify it via a command-line option or the NEDPATH environment variable.");
Register_GlobalConfigOption(CFGID_DEBUGGER_ATTACH_ON_STARTUP, "debugger-attach-on-startup", CFG_BOOL, "false", "When set to true, the simulation program will launch an external debugger attached to it, allowing you to set breakpoints before proceeding. The debugger command is configurable.  Note that debugging (i.e. attaching to) a non-child process needs to be explicitly enabled on some systems, e.g. Ubuntu.");
Register_GlobalConfigOption(CFGID_DEBUGGER_ATTACH_ON_ERROR, "debugger-attach-on-error", CFG_BOOL, "false", "When set to true, runtime errors and crashes will trigger an external debugger to be launched, allowing you to perform just-in-time debugging on the simulation process. The debugger command is configurable. Note that debugging (i.e. attaching to) a non-child process needs to be explicitly enabled on some systems, e.g. Ubuntu.");
Register_GlobalConfigOption(CFGID_DEBUGGER_ATTACH_COMMAND, "debugger-attach-command", CFG_STRING, DEFAULT_DEBUGGER_COMMAND, "Command line to launch the debugger. It must contain exactly one percent sign, as `%u`, which will be replaced by the PID of this process. The command must not block (i.e. it should end in `&` on Unix-like systems).");
Register_GlobalConfigOptionU(CFGID_DEBUGGER_ATTACH_WAIT_TIME, "debugger-attach-wait-time", "s", "20s", "An interval to wait after launching the external debugger, to give the debugger time to start up and attach to the simulation process.");

Register_PerRunConfigOption(CFGID_NETWORK, "network", CFG_STRING, nullptr, "The name of the network to be simulated.  The package name can be omitted if the ini file is in the same directory as the NED file that contains the network.");
Register_PerRunConfigOption(CFGID_WARNINGS, "warnings", CFG_BOOL, "true", "Enables warnings.");
Register_PerRunConfigOptionU(CFGID_SIM_TIME_LIMIT, "sim-time-limit", "s", nullptr, "Stops the simulation when simulation time reaches the given limit. The default is no limit.");
Register_PerRunConfigOptionU(CFGID_CPU_TIME_LIMIT, "cpu-time-limit", "s", nullptr, "Stops the simulation when CPU usage has reached the given limit. The default is no limit.");
Register_PerRunConfigOptionU(CFGID_WARMUP_PERIOD, "warmup-period", "s", nullptr, "Length of the initial warm-up period. When set, results belonging to the first x seconds of the simulation will not be recorded into output vectors, and will not be counted into output scalars (see option `**.result-recording-modes`). This option is useful for steady-state simulations. The default is 0s (no warmup period). Note that models that compute and record scalar results manually (via `recordScalar()`) will not automatically obey this setting.");
Register_PerRunConfigOption(CFGID_FINGERPRINT, "fingerprint", CFG_STRING, nullptr, "The expected fingerprints of the simulation. If you need multiple fingerprints, separate them with commas. When provided, the fingerprints will be calculated from the specified properties of simulation events, messages, and statistics during execution, and checked against the provided values. Fingerprints are suitable for crude regression tests. As fingerprints occasionally differ across platforms, more than one value can be specified for a single fingerprint, separated by spaces, and a match with any of them will be accepted. To obtain a fingerprint, enter a dummy value (such as `0000`), and run the simulation.");
#ifndef USE_OMNETPP4x_FINGERPRINTS
Register_GlobalConfigOption(CFGID_FINGERPRINTER_CLASS, "fingerprintcalculator-class", CFG_STRING, "omnetpp::cSingleFingerprintCalculator", "Part of the Envir plugin mechanism: selects the fingerprint calculator class to be used to calculate the simulation fingerprint. The class has to implement the `cFingerprintCalculator` interface.");
#endif
Register_PerRunConfigOption(CFGID_NUM_RNGS, "num-rngs", CFG_INT, "1", "The number of random number generators.");
Register_PerRunConfigOption(CFGID_RNG_CLASS, "rng-class", CFG_STRING, "omnetpp::cMersenneTwister", "The random number generator class to be used. It can be `cMersenneTwister`, `cLCG32`, `cAkaroaRNG`, or you can use your own RNG class (it must be subclassed from `cRNG`).");
Register_PerRunConfigOption(CFGID_SEED_SET, "seed-set", CFG_INT, "${runnumber}", "Selects the kth set of automatic random number seeds for the simulation. Meaningful values include `${repetition}` which is the repeat loop counter (see `repeat` option), and `${runnumber}`.");
Register_PerRunConfigOption(CFGID_RESULT_DIR, "result-dir", CFG_STRING, "results", "Value for the `${resultdir}` variable, which is used as the default directory for result files (output vector file, output scalar file, eventlog file, etc.)");
Register_PerRunConfigOption(CFGID_RECORD_EVENTLOG, "record-eventlog", CFG_BOOL, "false", "Enables recording an eventlog file, which can be later visualized on a sequence chart. See `eventlog-file` option too.");
Register_PerRunConfigOption(CFGID_DEBUG_STATISTICS_RECORDING, "debug-statistics-recording", CFG_BOOL, "false", "Turns on the printing of debugging information related to statistics recording (`@statistic` properties)");
Register_PerRunConfigOption(CFGID_CHECK_SIGNALS, "check-signals", CFG_BOOL, CHECKSIGNALS_DEFAULT, "Controls whether the simulation kernel will validate signals emitted by modules and channels against signal declarations (`@signal` properties) in NED files. The default setting depends on the build type: `true` in DEBUG, and `false` in RELEASE mode.");

Register_PerObjectConfigOption(CFGID_PARTITION_ID, "partition-id", KIND_MODULE, CFG_STRING, nullptr, "With parallel simulation: in which partition the module should be instantiated. Specify numeric partition ID, or a comma-separated list of partition IDs for compound modules that span across multiple partitions. Ranges (`5..9`) and `*` (=all) are accepted too.");
Register_PerObjectConfigOption(CFGID_RNG_K, "rng-%", KIND_COMPONENT, CFG_INT, "", "Maps a module-local RNG to one of the global RNGs. Example: `**.gen.rng-1=3` maps the local RNG 1 of modules matching `**.gen` to the global RNG 3. The value may be an expression, with the `index` and `ancestorIndex()` operators being potentially very useful. The default is one-to-one mapping, i.e. RNG k of all modules refer to the global RNG k (`for k=0..num-rngs-1`).\nUsage: `<module-full-path>.rng-<local-index>=<global-index>`. Examples: `**.mac.rng-0=1; **.source[*].rng-0=index`");
Register_PerObjectConfigOption(CFGID_STATISTIC_RECORDING, "statistic-recording", KIND_STATISTIC, CFG_BOOL, "true", "Whether the matching `@statistic` should be recorded. This option lets one completely disable all recording from a @statistic. Disabling a `@statistic` this way is more efficient than specifying `**.scalar-recording=false` and `**.vector-recording=false` together.\nUsage: `<module-full-path>.<statistic-name>.statistic-recording=true/false`.\nExample: `**.ping.roundTripTime.statistic-recording=false`");
Register_PerObjectConfigOption(CFGID_RESULT_RECORDING_MODES, "result-recording-modes", KIND_STATISTIC, CFG_STRING, "default", "Defines how to calculate results from the matching `@statistic`.\nUsage: `<module-full-path>.<statistic-name>.result-recording-modes=<modes>`. Special values: `default`, `all`: they select the modes listed in the `record` key of `@statistic`; all selects all of them, default selects the non-optional ones (i.e. excludes the ones that end in a question mark). Example values: `vector`, `count`, `last`, `sum`, `mean`, `min`, `max`, `timeavg`, `stats`, `histogram`. More than one values are accepted, separated by commas. Expressions are allowed. Items prefixed with `-` get removed from the list. Example: `**.queueLength.result-recording-modes=default,-vector,+timeavg`");

#define STRINGIZE0(x)    #x
#define STRINGIZE(x)     STRINGIZE0(x)

static const char *compilerInfo =
    #if defined __GNUC__
    "GCC " __VERSION__
    #elif defined _MSC_VER
    "Microsoft Visual C++ version " STRINGIZE(_MSC_VER)
    #elif defined __INTEL_COMPILER
    "Intel Compiler version " STRINGIZE(__INTEL_COMPILER)
    #else
    "unknown-compiler"
    #endif
    ;

static const char *buildInfoFormat =
    "%d-bit"

    #ifdef NDEBUG
    " RELEASE"
    #else
    " DEBUG"
    #endif

    " simtime_t=%s"
    " large-file-support=%s"
    ;

static const char *buildOptions = ""
    #ifdef WITH_PARSIM
    " WITH_PARSIM"
    #endif

    #ifdef WITH_MPI
    " WITH_MPI"
    #endif

    #ifdef WITH_NETBUILDER
    " WITH_NETBUILDER"
    #endif

    #ifdef WITH_TKENV
    " WITH_TKENV"
    #endif

    #ifdef WITH_QTENV
    " WITH_QTENV"
    #endif

    #ifdef WITH_OSG
    " WITH_OSG"
    #endif

    #ifdef WITH_AKAROA
    " WITH_AKAROA"
    #endif

    #ifdef XMLPARSER
    " XMLPARSER=" STRINGIZE(XMLPARSER)
    #endif
    ;


EnvirOptions::EnvirOptions()
{
    // note: these values will be overwritten in setup()/readOptions() before taking effect
    totalStack = 0;
    parsim = false;
    numRNGs = 1;
    seedset = 0;
    debugStatisticsRecording = false;
    checkSignals = false;
    fnameAppendHost = false;
    warnings = true;
    printUndisposed = true;
    cpuTimeLimit = 0;
}

EnvirBase::EnvirBase()
{
    opt = nullptr;
    args = nullptr;
    cfg = nullptr;
    xmlCache = nullptr;

    recordEventlog = false;
    eventlogManager = nullptr;
    outvectorManager = nullptr;
    outScalarManager = nullptr;
    snapshotManager = nullptr;

    numRNGs = 0;
    rngs = nullptr;

#ifdef WITH_PARSIM
    parsimComm = nullptr;
    parsimPartition = nullptr;
#endif

    exitCode = 0;
}

EnvirBase::~EnvirBase()
{
    while (!listeners.empty()) {
        listeners.back()->listenerRemoved();
        listeners.pop_back();
    }

    delete opt;
    delete args;
    delete cfg;
    delete xmlCache;

    delete eventlogManager;
    delete outvectorManager;
    delete outScalarManager;
    delete snapshotManager;

    for (int i = 0; i < numRNGs; i++)
        delete rngs[i];
    delete[] rngs;

#ifdef WITH_PARSIM
    delete parsimComm;
    delete parsimPartition;
#endif
}

int EnvirBase::run(int argc, char *argv[], cConfiguration *configobject)
{
    opt = createOptions();
    args = new ArgList();
    args->parse(argc, argv, "h?f:u:l:c:r:n:p:x:X:agGvw");  // TODO share spec with startup.cc!
    cfg = dynamic_cast<cConfigurationEx *>(configobject);
    if (!cfg)
        throw cRuntimeError("Cannot cast configuration object %s to cConfigurationEx", configobject->getClassName());
    if (cfg->getAsBool(CFGID_DEBUGGER_ATTACH_ON_STARTUP))
        attachDebugger();

    if (simulationRequired()) {
        if (setup())
            run();  // must not throw, because we want shutdown() always to be called
        shutdown();
    }
    return exitCode;
}

bool EnvirBase::simulationRequired()
{
    // handle -h and -v command-line options
    if (args->optionGiven('h')) {
        const char *category = args->optionValue('h', 0);
        if (!category)
            printHelp();
        else
            EnvirUtils::dumpComponentList(category);
        return false;
    }

    if (args->optionGiven('v')) {
        struct opp_stat_t statbuf;
        std::cout << "\n";
        std::cout << "Build: " OMNETPP_RELEASE " " OMNETPP_BUILDID << "\n";
        std::cout << "Compiler: " << compilerInfo << "\n";
        std::cout << "Options: " << opp_stringf(buildInfoFormat,
                8*sizeof(void *),
                opp_typename(typeid(simtime_t)),
                sizeof(statbuf.st_size) >= 8 ? "yes" : "no");
        std::cout << buildOptions << "\n";
        return false;
    }

    cConfigurationEx *cfg = getConfigEx();

    // -a option: print all config names, and number of runs in them
    if (args->optionGiven('a')) {
        std::cout << "\n";
        std::vector<std::string> configNames = cfg->getConfigNames();
        for (int i = 0; i < (int)configNames.size(); i++)
            std::cout << "Config " << configNames[i] << ": " << cfg->getNumRunsInConfig(configNames[i].c_str()) << "\n";
        return false;
    }

    // '-x' option: print number of runs in the given config, and exit (overrides configname)
    const char *configToPrint = args->optionValue('x');
    if (configToPrint) {
        //
        // IMPORTANT: the simulation launcher will parse the output of this
        // option, so it should be modified with care and the two kept in sync
        // (see OmnetppLaunchUtils.getSimulationRunInfo()).
        //
        // Rules:
        // (1) the number of runs should appear on the rest of the line
        //     after the "Number of runs:" text
        // (2) per-run information lines should span from the "Number of runs:"
        //     line until the next blank line ("\n\n").
        //

        // '-g'/'-G' options: modifies -x: print unrolled config, iteration variables, etc as well
        bool unrollBrief = args->optionGiven('g');
        bool unrollDetailed = args->optionGiven('G');

        std::cout <<"\n";
        std::cout <<"Config: " << configToPrint << "\n";
        std::cout <<"Number of runs: " << cfg->getNumRunsInConfig(configToPrint) << "\n";

        if (unrollBrief || unrollDetailed) {
            std::vector<std::string> runs = cfg->unrollConfig(configToPrint, unrollDetailed);
            const char *fmt = unrollDetailed ? "Run %d:\n%s" : "Run %d: %s\n";
            for (int i = 0; i < (int)runs.size(); i++)
                std::cout << opp_stringf(fmt, i, runs[i].c_str());
        }
        return false;
    }

    // -X option: print fallback chain of the given config, and exit
    configToPrint = args->optionValue('X');
    if (configToPrint) {
        std::cout << "\n";
        std::vector<std::string> configNames = cfg->getConfigChain(configToPrint);
        for (int i = 0; i < (int)configNames.size(); i++) {
            std::string configName = configNames[i];
            if (configName != "General")
                std::cout << "Config ";
            std::cout << configName << "\n";
        }
        return false;
    }

    return true;
}

bool EnvirBase::setup()
{
    try {
        // ensure correct numeric format in output files
        setPosixLocale();

        // set opt->* variables from ini file(s)
        readOptions();

        if (getConfig()->getAsBool(CFGID_DEBUGGER_ATTACH_ON_ERROR)) {
            signal(SIGSEGV, crashHandler);
            signal(SIGILL, crashHandler);
#ifndef _WIN32
            signal(SIGBUS, crashHandler);
            signal(SIGUSR1, crashHandler);
#endif
        }

        // initialize coroutine library
        if (TOTAL_STACK_SIZE != 0 && opt->totalStack <= MAIN_STACK_SIZE+4096) {
            std::cout << "Total stack size " << opt->totalStack << " increased to " << MAIN_STACK_SIZE << "\n";
            opt->totalStack = MAIN_STACK_SIZE+4096;
        }
        cCoroutine::init(opt->totalStack, MAIN_STACK_SIZE);

        // install XML document cache
        xmlCache = new cXMLDocCache();

        // install eventlog manager
        CREATE_BY_CLASSNAME(eventlogManager, opt->eventlogManagerClass.c_str(), cIEventlogManager, "eventlog manager");

        // install output vector manager
        CREATE_BY_CLASSNAME(outvectorManager, opt->outputVectorManagerClass.c_str(), cIOutputVectorManager, "output vector manager");
        addLifecycleListener(outvectorManager);

        // install output scalar manager
        CREATE_BY_CLASSNAME(outScalarManager, opt->outputScalarManagerClass.c_str(), cIOutputScalarManager, "output scalar manager");
        addLifecycleListener(outScalarManager);

        // install snapshot manager
        CREATE_BY_CLASSNAME(snapshotManager, opt->snapshotmanagerClass.c_str(), cISnapshotManager, "snapshot manager");
        addLifecycleListener(snapshotManager);

        // install FES
        cFutureEventSet *fes;
        CREATE_BY_CLASSNAME(fes, opt->futureeventsetClass.c_str(), cFutureEventSet, "FES");
        getSimulation()->setFES(fes);

        // set up for sequential or distributed execution
        if (!opt->parsim) {
            // sequential
            cScheduler *scheduler;
            CREATE_BY_CLASSNAME(scheduler, opt->schedulerClass.c_str(), cScheduler, "event scheduler");
            getSimulation()->setScheduler(scheduler);
        }
        else {
#ifdef WITH_PARSIM
            // parsim: create components
            CREATE_BY_CLASSNAME(parsimComm, opt->parsimcommClass.c_str(), cParsimCommunications, "parallel simulation communications layer");
            parsimPartition = new cParsimPartition();
            cParsimSynchronizer *parsimSynchronizer;
            CREATE_BY_CLASSNAME(parsimSynchronizer, opt->parsimsynchClass.c_str(), cParsimSynchronizer, "parallel simulation synchronization layer");
            addLifecycleListener(parsimPartition);

            // wire them together (note: 'parsimSynchronizer' is also the scheduler for 'simulation')
            parsimPartition->setContext(getSimulation(), parsimComm, parsimSynchronizer);
            parsimSynchronizer->setContext(getSimulation(), parsimPartition, parsimComm);
            getSimulation()->setScheduler(parsimSynchronizer);

            // initialize them
            parsimComm->init();
#else
            throw cRuntimeError("Parallel simulation is turned on in the ini file, but OMNeT++ was compiled without parallel simulation support (WITH_PARSIM=no)");
#endif
        }

        // load NED files from folders on the NED path
        StringTokenizer tokenizer(opt->nedPath.c_str(), PATH_SEPARATOR);
        std::set<std::string> foldersLoaded;
        while (tokenizer.hasMoreTokens()) {
            const char *folder = tokenizer.nextToken();
            if (foldersLoaded.find(folder) == foldersLoaded.end()) {
                std::cout << "Loading NED files from " << folder << ": ";
                int count = getSimulation()->loadNedSourceFolder(folder);
                std::cout << " " << count << endl;
                foldersLoaded.insert(folder);
            }
        }
        getSimulation()->doneLoadingNedFiles();

        // notify listeners when global setup is complete
        notifyLifecycleListeners(LF_ON_STARTUP);
    }
    catch (std::exception& e) {
        displayException(e);
        exitCode = 1;
        return false;  // don't run the app
    }
    return true;
}

void EnvirBase::printHelp()
{
    std::cout << "\n";
    std::cout << "Command line options:\n";
    std::cout << "  <inifile> or -f <inifile>\n";
    std::cout << "                Use the given ini file instead of omnetpp.ini. More than one\n";
    std::cout << "                ini files can be loaded this way.\n";
    std::cout << "  -u <ui>       Selects the user interface. Standard choices are Cmdenv\n";
    std::cout << "                and Tkenv. To make a user interface available, you need\n";
    std::cout << "                to link the simulation executable with the Cmdenv/Tkenv\n";
    std::cout << "                library, or load it as shared library via the -l option.\n";
    std::cout << "  -n <nedpath>  When present, overrides the NEDPATH environment variable.\n";
    std::cout << "  -l <library>  Load the specified shared library (.so or .dll) on startup.\n";
    std::cout << "                The file name should be given without the .so or .dll suffix\n";
    std::cout << "                (it will be appended automatically.) The loaded module may\n";
    std::cout << "                contain simple modules, plugins, etc. Multiple -l options\n";
    std::cout << "                can be present.\n";
    std::cout << "  -p <port>     Port number for the built-in web server.\n";
    std::cout << "                If the port is not available, the program will exit with an\n";
    std::cout << "                error message unless the number is suffixed with the plus\n";
    std::cout << "                sign. The plus sign causes the program to search for the\n";
    std::cout << "                first available port number above the given one, and not stop\n";
    std::cout << "                with an error even if no available port was found. A plain\n";
    std::cout << "                minus sign will turn off the built-in web server.\n";
    std::cout << "                The default value is \"8000+\".\n";
    std::cout << "  --<configuration-key>=<value>\n";
    std::cout << "                Any configuration option can be specified on the command\n";
    std::cout << "                line, and it takes precedence over settings specified in the\n";
    std::cout << "                ini file(s). Examples:\n";
    std::cout << "                      --debug-on-errors=true\n";
    std::cout << "                      --record-eventlog=true\n";
    std::cout << "                      --sim-time-limit=1000s\n";
    std::cout << "  -v            Print version and build info.\n";
    std::cout << "  -h            Print this help and exit.\n";
    std::cout << "  -h <category> Lists registered components:\n";
    std::cout << "    -h config         Prints the list of available config options\n";
    std::cout << "    -h configdetails  Prints the list of available config options, with\n";
    std::cout << "                      their documentation\n";
    std::cout << "    -h userinterfaces Lists available user interfaces (see -u option)\n";
    std::cout << "    -h classes        Lists registered C++ classes (including module classes)\n";
    std::cout << "    -h classdesc      Lists C++ classes that have associated reflection\n";
    std::cout << "                      information (needed for Tkenv inspectors)\n";
    std::cout << "    -h nedfunctions   Lists registered NED functions\n";
    std::cout << "    -h neddecls       Lists built-in NED component declarations\n";
    std::cout << "    -h units          Lists recognized physical units\n";
    std::cout << "    -h enums          Lists registered enums\n";
    std::cout << "    -h resultfilters  Lists result filters\n";
    std::cout << "    -h resultrecorders Lists result recorders\n";
    std::cout << "    -h figures        Lists available figure types\n";
    std::cout << "    -h all            Union of all the above\n";
    std::cout << "\n";

    // print specific help for each user interface
    cRegistrationList *table = omnetapps.getInstance();
    table->sort();
    for (int i = 0; i < table->size(); i++) {
        // instantiate the ui, call printUISpecificHelp(), then dispose.
        // note: their ctors are not supposed to do anything but trivial member initializations
        cOmnetAppRegistration *appreg = dynamic_cast<cOmnetAppRegistration *>(table->get(i));
        ASSERT(appreg != nullptr);
        cEnvir *app = appreg->createOne();
        if (EnvirBase *app2 = dynamic_cast<EnvirBase *>(app))
            app2->printUISpecificHelp();
        delete app;
    }
}

int EnvirBase::getParsimProcId() const
{
#ifdef WITH_PARSIM
    return parsimComm ? parsimComm->getProcId() : 0;
#else
    return 0;
#endif
}

int EnvirBase::getParsimNumPartitions() const
{
#ifdef WITH_PARSIM
    return parsimComm ? parsimComm->getNumPartitions() : 0;
#else
    return 0;
#endif
}

void EnvirBase::run()
{
    try {
        doRun();
    }
    catch (std::exception& e) {
        displayException(e);
    }
}

void EnvirBase::shutdown()
{
    try {
        getSimulation()->deleteNetwork();
        notifyLifecycleListeners(LF_ON_SHUTDOWN);
    }
    catch (std::exception& e) {
        displayException(e);
    }
}

void EnvirBase::setupNetwork(cModuleType *network)
{
    currentEventName = "";
    currentEventClassName = nullptr;
    currentModuleId = -1;

    getSimulation()->setupNetwork(network);
    eventlogManager->flush();
}

void EnvirBase::startRun()
{
    resetClock();
    if (opt->simtimeLimit > SIMTIME_ZERO)
        getSimulation()->setSimulationTimeLimit(opt->simtimeLimit);
    getSimulation()->callInitialize();
    cLogProxy::flushLastLine();
}

void EnvirBase::endRun()  // FIXME eliminate???
{
    notifyLifecycleListeners(LF_ON_RUN_END);
}

//-------------------------------------------------------------

void EnvirBase::preconfigure(cComponent *component)
{
    setupRNGMapping(component);
}

void EnvirBase::configure(cComponent *component)
{
    addResultRecorders(component);
}

static int search_(std::vector<std::string>& v, const char *s)
{
    for (int i = 0; i < (int)v.size(); i++)
        if (strcmp(v[i].c_str(), s) == 0)
            return i;
    return -1;
}

inline void addIfNotContains_(std::vector<std::string>& v, const char *s)
{
    if (search_(v, s) == -1)
        v.push_back(s);
}

inline void addIfNotContains_(std::vector<std::string>& v, const std::string& s)
{
    if (search_(v, s.c_str()) == -1)
        v.push_back(s);
}

void EnvirBase::addResultRecorders(cComponent *component)
{
    std::vector<const char *> statisticNames = component->getProperties()->getIndicesFor("statistic");
    std::string componentFullPath;
    for (int i = 0; i < (int)statisticNames.size(); i++) {
        if (componentFullPath.empty())
            componentFullPath = component->getFullPath();
        const char *statisticName = statisticNames[i];
        cProperty *statisticProperty = component->getProperties()->get("statistic", statisticName);
        ASSERT(statisticProperty != nullptr);
        doAddResultRecorders(component, componentFullPath, statisticName, statisticProperty, SIMSIGNAL_NULL);
    }

    if (opt->debugStatisticsRecording)
        EnvirUtils::dumpResultRecorders(component);
}

void EnvirBase::addResultRecorders(cComponent *component, simsignal_t signal, const char *statisticName, cProperty *statisticTemplateProperty)
{
    std::string dummy;
    doAddResultRecorders(component, dummy, statisticName, statisticTemplateProperty, signal);
}

void EnvirBase::doAddResultRecorders(cComponent *component, std::string& componentFullPath, const char *statisticName, cProperty *statisticProperty, simsignal_t signal)
{
    if (componentFullPath.empty())
        componentFullPath = component->getFullPath();
    std::string statisticFullPath = componentFullPath + "." + statisticName;

    bool enabled = getConfig()->getAsBool(statisticFullPath.c_str(), CFGID_STATISTIC_RECORDING);
    if (!enabled)
        return;

    // collect the list of result recorders
    std::string modesOption = getConfig()->getAsString(statisticFullPath.c_str(), CFGID_RESULT_RECORDING_MODES, "");
    std::vector<std::string> modes = extractRecorderList(modesOption.c_str(), statisticProperty);

    // if there are result recorders, add source filters and recorders
    if (!modes.empty()) {
        // determine source: use either the signal from the argument list, or the source= key in the @statistic property
        SignalSource source;
        if (signal == SIMSIGNAL_NULL) {
            bool hasSourceKey = statisticProperty->getNumValues("source") > 0;
            const char *sourceSpec = hasSourceKey ? statisticProperty->getValue("source", 0) : statisticName;
            source = doStatisticSource(component, statisticName, sourceSpec, opt->warmupPeriod != 0);
        }
        else {
            source = SignalSource(component, signal);
        }

        // add result recorders
        for (int j = 0; j < (int)modes.size(); j++)
            doResultRecorder(source, modes[j].c_str(), component, statisticName, statisticProperty);
    }
}

std::vector<std::string> EnvirBase::extractRecorderList(const char *modesOption, cProperty *statisticProperty)
{
    // "-" means "none"
    if (!modesOption[0] || (modesOption[0] == '-' && !modesOption[1]))
        return std::vector<std::string>();

    std::vector<std::string> modes;  // the result

    // if first configured mode starts with '+' or '-', assume "default" as base
    if (modesOption[0] == '-' || modesOption[0] == '+') {
        // collect the mandatory record= items from @statistic (those not ending in '?')
        int n = statisticProperty->getNumValues("record");
        for (int i = 0; i < n; i++) {
            const char *m = statisticProperty->getValue("record", i);
            if (m[strlen(m)-1] != '?')
                addIfNotContains_(modes, m);
        }
    }

    // loop through all modes
    StringTokenizer tokenizer(modesOption, ",");  // XXX we should ignore commas within parens
    while (tokenizer.hasMoreTokens()) {
        const char *mode = tokenizer.nextToken();
        if (!strcmp(mode, "default")) {
            // collect the mandatory record= items from @statistic (those not ending in '?')
            int n = statisticProperty->getNumValues("record");
            for (int i = 0; i < n; i++) {
                const char *m = statisticProperty->getValue("record", i);
                if (m[strlen(m)-1] != '?')
                    addIfNotContains_(modes, m);
            }
        }
        else if (!strcmp(mode, "all")) {
            // collect all record= items from @statistic (strip trailing '?' if present)
            int n = statisticProperty->getNumValues("record");
            for (int i = 0; i < n; i++) {
                const char *m = statisticProperty->getValue("record", i);
                if (m[strlen(m)-1] != '?')
                    addIfNotContains_(modes, m);
                else
                    addIfNotContains_(modes, std::string(m, strlen(m)-1));
            }
        }
        else if (mode[0] == '-') {
            // remove from modes
            int k = search_(modes, mode+1);
            if (k != -1)
                modes.erase(modes.begin()+k);
        }
        else {
            // add to modes
            addIfNotContains_(modes, mode[0] == '+' ? mode+1 : mode);
        }
    }
    return modes;
}

static bool opp_isidentifier(const char *s)
{
    if (!opp_isalphaext(s[0]) && s[0] != '_')
        return false;
    while (*++s)
        if (!opp_isalnumext(*s) && s[0] != '_')
            return false;

    return true;
}

SignalSource EnvirBase::doStatisticSource(cComponent *component, const char *statisticName, const char *sourceSpec, bool needWarmupFilter)
{
    try {
        if (opp_isidentifier(sourceSpec)) {
            // simple case: just a signal name
            simsignal_t signalID = cComponent::registerSignal(sourceSpec);
            if (!needWarmupFilter)
                return SignalSource(component, signalID);
            else {
                WarmupPeriodFilter *warmupFilter = new WarmupPeriodFilter();
                component->subscribe(signalID, warmupFilter);
                return SignalSource(warmupFilter);
            }
        }
        else {
            StatisticSourceParser parser;
            return parser.parse(component, statisticName, sourceSpec, needWarmupFilter);
        }
    }
    catch (std::exception& e) {
        throw cRuntimeError("Error adding statistic '%s' to module %s (NED type: %s): error in source=%s: %s",
                statisticName, component->getFullPath().c_str(), component->getNedTypeName(), sourceSpec, e.what());
    }
}

void EnvirBase::doResultRecorder(const SignalSource& source, const char *recordingMode, cComponent *component, const char *statisticName, cProperty *attrsProperty)
{
    try {
        if (opp_isidentifier(recordingMode)) {
            // simple case: just a plain recorder
            //TODO if disabled, don't add
            cResultRecorder *recorder = cResultRecorderDescriptor::get(recordingMode)->create();
            recorder->init(component, statisticName, recordingMode, attrsProperty);
            source.subscribe(recorder);
        }
        else {
            // something more complicated: use parser
            StatisticRecorderParser parser;
            parser.parse(source, recordingMode, component, statisticName, attrsProperty);
        }
    }
    catch (std::exception& e) {
        throw cRuntimeError("Error adding statistic '%s' to module %s (NED type: %s): bad recording mode '%s': %s",
                statisticName, component->getFullPath().c_str(), component->getNedTypeName(), recordingMode, e.what());
    }
}

void EnvirBase::readParameter(cPar *par)
{
    ASSERT(!par->isSet());  // must be unset at this point

    // get it from the ini file
    std::string moduleFullPath = par->getOwner()->getFullPath();
    const char *str = getConfigEx()->getParameterValue(moduleFullPath.c_str(), par->getName(), par->containsValue());

/* XXX hack to use base directory for resolving xml files location has been commented out
 * FIXME a solution needs to be worked out!
    if (str[0]=='x' && !strncmp(str,"xmldoc",6) && !opp_isalnum(str[6]))
    {
        // Make XML file location relative to the ini file in which it occurs.
        // Find substring between first two quotes (that is, the XML filename),
        // and prefix it with the directory.
        const char *begQuote = strchr(str+6,'"');
        if (!begQuote)
            return std::string(str);
        const char *endQuote = strchr(begQuote+1,'"');
        while (endQuote && *(endQuote-1)=='\\' && *(endQuote-2)!='\\')
            endQuote = strchr(endQuote+1,'"');
        if (!endQuote)
            return std::string(str);
        std::string fname(begQuote+1, endQuote-begQuote-1);
        const char *baseDir = getConfig()->getBaseDirectoryFor(nullptr, "Parameters", parname);
        fname = tidyFilename(concatDirAndFile(baseDir, fname.c_str()).c_str(),true);
        std::string ret = std::string(str, begQuote-str+1) + fname + endQuote;
        //XXX use "ret" further!!!
    }
*/

    if (omnetpp::opp_strcmp(str, "default") == 0) {
        ASSERT(par->containsValue());  // cConfiguration should not return "=default" lines for params that have no default value
        par->acceptDefault();
    }
    else if (omnetpp::opp_strcmp(str, "ask") == 0) {
        askParameter(par, false);
    }
    else if (!opp_isempty(str)) {
        par->parse(str);
    }
    else {
        // str empty: no value in the ini file
        if (par->containsValue())
            par->acceptDefault();
        else
            askParameter(par, true);
    }

    ASSERT(par->isSet());  // and must be set after
}

bool EnvirBase::isModuleLocal(cModule *parentmod, const char *modname, int index)
{
#ifdef WITH_PARSIM
    if (!opt->parsim)
        return true;

    // toplevel module is local everywhere
    if (!parentmod)
        return true;

    // find out if this module is (or has any submodules that are) on this partition
    char parname[MAX_OBJECTFULLPATH];
    if (index < 0)
        sprintf(parname, "%s.%s", parentmod->getFullPath().c_str(), modname);
    else
        sprintf(parname, "%s.%s[%d]", parentmod->getFullPath().c_str(), modname, index);  // FIXME this is incorrectly chosen for non-vector modules too!
    std::string procIds = getConfig()->getAsString(parname, CFGID_PARTITION_ID, "");
    if (procIds.empty()) {
        // modules inherit the setting from their parents, except when the parent is the system module (the network) itself
        if (!parentmod->getParentModule())
            throw cRuntimeError("incomplete partitioning: missing value for '%s'", parname);
        // "true" means "inherit", because an ancestor which answered "false" doesn't get recursed into
        return true;
    }
    else if (strcmp(procIds.c_str(), "*") == 0) {
        // present on all partitions (provided that ancestors have "*" set as well)
        return true;
    }
    else {
        // we expect a partition Id (or partition Ids, separated by commas) where this
        // module needs to be instantiated. So we return true if any of the numbers
        // is the Id of the local partition, otherwise false.
        EnumStringIterator procIdIter(procIds.c_str());
        if (procIdIter.hasError())
            throw cRuntimeError("wrong partitioning: syntax error in value '%s' for '%s' "
                                "(allowed syntax: '', '*', '1', '0,3,5-7')",
                    procIds.c_str(), parname);
        int numPartitions = parsimComm->getNumPartitions();
        int myProcId = parsimComm->getProcId();
        for ( ; procIdIter() != -1; procIdIter++) {
            if (procIdIter() >= numPartitions)
                throw cRuntimeError("wrong partitioning: value %d too large for '%s' (total partitions=%d)",
                        procIdIter(), parname, numPartitions);
            if (procIdIter() == myProcId)
                return true;
        }
        return false;
    }
#else
    return true;
#endif
}

cXMLElement *EnvirBase::getXMLDocument(const char *filename, const char *path)
{
    cXMLElement *documentnode = xmlCache->getDocument(filename);
    return resolveXMLPath(documentnode, path);
}

cXMLElement *EnvirBase::getParsedXMLString(const char *content, const char *path)
{
    cXMLElement *documentnode = xmlCache->getParsed(content);
    return resolveXMLPath(documentnode, path);
}

cXMLElement *EnvirBase::resolveXMLPath(cXMLElement *documentnode, const char *path)
{
    assert(documentnode);
    if (path) {
        ModNameParamResolver resolver(getSimulation()->getContextModule());  // resolves $MODULE_NAME etc in XPath expr.
        return cXMLElement::getDocumentElementByPath(documentnode, path, &resolver);
    }
    else {
        // returns the root element (child of the document node)
        return documentnode->getFirstChild();
    }
}

void EnvirBase::forgetXMLDocument(const char *filename)
{
    xmlCache->forgetDocument(filename);
}

void EnvirBase::forgetParsedXMLString(const char *content)
{
    xmlCache->forgetParsed(content);
}

void EnvirBase::flushXMLDocumentCache()
{
    xmlCache->flushDocumentCache();
}

void EnvirBase::flushXMLParsedContentCache()
{
    xmlCache->flushParsedContentCache();
}

cConfiguration *EnvirBase::getConfig()
{
    return cfg;
}

cConfigurationEx *EnvirBase::getConfigEx()
{
    return cfg;
}

std::string EnvirBase::resolveResourcePath(const char *fileName, cComponentType *context)
{
    // search in current directory (or with absolute path)
    if (fileExists(fileName))
        return fileName;

    // search folder of the primary ini file
    const char *inifile = cfg->getFileName();
    if (!opp_isempty(inifile)) {
        std::string iniDir = directoryOf(inifile);
        std::string path = concatDirAndFile(iniDir.c_str(), fileName);
        if (fileExists(path.c_str()))
            return tidyFilename(path.c_str());
    }

    // search in the NED folder of the context component type
    const char *nedFile = context ? context->getSourceFileName() : nullptr;
    if (nedFile) {
        std::string dir = directoryOf(nedFile);
        std::string path = concatDirAndFile(dir.c_str(), fileName);
        if (fileExists(path.c_str()))
            return tidyFilename(path.c_str());
    }

    // search the NED path
    StringTokenizer nedTokenizer(opt->nedPath.c_str(), PATH_SEPARATOR);
    while (nedTokenizer.hasMoreTokens()) {
        const char *dir = nedTokenizer.nextToken();
        std::string path = concatDirAndFile(dir, fileName);
        if (fileExists(path.c_str()))
            return tidyFilename(path.c_str());
    }

    // search the image path
    StringTokenizer imgTokenizer(opt->imagePath.c_str(), PATH_SEPARATOR);
    while (imgTokenizer.hasMoreTokens()) {
        const char *dir = imgTokenizer.nextToken();
        std::string path = concatDirAndFile(dir, fileName);
        if (fileExists(path.c_str()))
            return tidyFilename(path.c_str());
    }

    return ""; // not found
}

//-------------------------------------------------------------

void EnvirBase::bubble(cComponent *component, const char *text)
{
    if (recordEventlog)
        eventlogManager->bubble(component, text);
}

void EnvirBase::objectDeleted(cObject *object)
{
    // TODO?
}

void EnvirBase::simulationEvent(cEvent *event)
{
    if (logFormatUsesEventName)
        currentEventName = event->getFullName();
    currentEventClassName = event->getClassName();
    currentModuleId = event->isMessage() ? (static_cast<cMessage *>(event))->getArrivalModule()->getId() : -1;
    if (recordEventlog)
        eventlogManager->simulationEvent(event);
}

void EnvirBase::beginSend(cMessage *msg)
{
    if (recordEventlog)
        eventlogManager->beginSend(msg);
}

void EnvirBase::messageScheduled(cMessage *msg)
{
    if (recordEventlog)
        eventlogManager->messageScheduled(msg);
}

void EnvirBase::messageCancelled(cMessage *msg)
{
    if (recordEventlog)
        eventlogManager->messageCancelled(msg);
}

void EnvirBase::messageSendDirect(cMessage *msg, cGate *toGate, simtime_t propagationDelay, simtime_t transmissionDelay)
{
    if (recordEventlog)
        eventlogManager->messageSendDirect(msg, toGate, propagationDelay, transmissionDelay);
}

void EnvirBase::messageSendHop(cMessage *msg, cGate *srcGate)
{
    if (recordEventlog)
        eventlogManager->messageSendHop(msg, srcGate);
}

void EnvirBase::messageSendHop(cMessage *msg, cGate *srcGate, simtime_t propagationDelay, simtime_t transmissionDelay)
{
    if (recordEventlog)
        eventlogManager->messageSendHop(msg, srcGate, propagationDelay, transmissionDelay);
}

void EnvirBase::endSend(cMessage *msg)
{
    if (recordEventlog)
        eventlogManager->endSend(msg);
}

void EnvirBase::messageCreated(cMessage *msg)
{
    if (recordEventlog)
        eventlogManager->messageCreated(msg);
}

void EnvirBase::messageCloned(cMessage *msg, cMessage *clone)
{
    if (recordEventlog)
        eventlogManager->messageCloned(msg, clone);
}

void EnvirBase::messageDeleted(cMessage *msg)
{
    if (recordEventlog)
        eventlogManager->messageDeleted(msg);
}

void EnvirBase::componentMethodBegin(cComponent *from, cComponent *to, const char *methodFmt, va_list va, bool silent)
{
    if (recordEventlog)
        eventlogManager->componentMethodBegin(from, to, methodFmt, va);
}

void EnvirBase::componentMethodEnd()
{
    if (recordEventlog)
        eventlogManager->componentMethodEnd();
}

void EnvirBase::moduleCreated(cModule *newmodule)
{
    if (recordEventlog)
        eventlogManager->moduleCreated(newmodule);
}

void EnvirBase::moduleDeleted(cModule *module)
{
    if (recordEventlog)
        eventlogManager->moduleDeleted(module);
}

void EnvirBase::moduleReparented(cModule *module, cModule *oldparent, int oldId)
{
    if (recordEventlog)
        eventlogManager->moduleReparented(module, oldparent, oldId);
}

void EnvirBase::gateCreated(cGate *newgate)
{
    if (recordEventlog)
        eventlogManager->gateCreated(newgate);
}

void EnvirBase::gateDeleted(cGate *gate)
{
    if (recordEventlog)
        eventlogManager->gateDeleted(gate);
}

void EnvirBase::connectionCreated(cGate *srcgate)
{
    if (recordEventlog)
        eventlogManager->connectionCreated(srcgate);
}

void EnvirBase::connectionDeleted(cGate *srcgate)
{
    if (recordEventlog)
        eventlogManager->connectionDeleted(srcgate);
}

void EnvirBase::displayStringChanged(cComponent *component)
{
    if (recordEventlog)
        eventlogManager->displayStringChanged(component);
}

void EnvirBase::log(cLogEntry *entry)
{
    if (recordEventlog) {
        std::string prefix = logFormatter.formatPrefix(entry);
        eventlogManager->logLine(prefix.c_str(), entry->text, entry->textLength);
    }
}

void EnvirBase::undisposedObject(cObject *obj)
{
    if (opt->printUndisposed)
        ::printf("undisposed object: (%s) %s -- check module destructor\n", obj->getClassName(), obj->getFullPath().c_str());
}

//-------------------------------------------------------------

void EnvirBase::processFileName(std::string& fname)
{
    // insert ".<hostname>.<pid>" if requested before file extension
    // (note: parsimProcId cannot be appended because of initialization order)
    if (opt->fnameAppendHost) {
        std::string extension = "";
        std::string::size_type index = fname.rfind('.');
        if (index != std::string::npos) {
            extension = std::string(fname, index);
            fname.erase(index);
        }

        const char *hostname = opp_gethostname();
        if (!hostname)
            throw cRuntimeError("Cannot append hostname to file name `%s': no HOST, HOSTNAME "
                                "or COMPUTERNAME (Windows) environment variable", fname.c_str());
        int pid = getpid();

        // append
        fname += opp_stringf(".%s.%d%s", hostname, pid, extension.c_str());
    }
}

void EnvirBase::readOptions()
{
    cConfiguration *cfg = getConfig();

    opt->totalStack = (size_t)cfg->getAsDouble(CFGID_TOTAL_STACK, TOTAL_STACK_SIZE);
    opt->parsim = cfg->getAsBool(CFGID_PARALLEL_SIMULATION);
    if (!opt->parsim) {
        opt->schedulerClass = cfg->getAsString(CFGID_SCHEDULER_CLASS);
    }
    else {
#ifdef WITH_PARSIM
        opt->parsimcommClass = cfg->getAsString(CFGID_PARSIM_COMMUNICATIONS_CLASS);
        opt->parsimsynchClass = cfg->getAsString(CFGID_PARSIM_SYNCHRONIZATION_CLASS);
#else
        throw cRuntimeError("Parallel simulation is turned on in the ini file, but OMNeT++ was compiled without parallel simulation support (WITH_PARSIM=no)");
#endif
    }

    opt->futureeventsetClass = cfg->getAsString(CFGID_FUTUREEVENTSET_CLASS);

    opt->eventlogManagerClass = cfg->getAsString(CFGID_EVENTLOGMANAGER_CLASS);
    opt->outputVectorManagerClass = cfg->getAsString(CFGID_OUTPUTVECTORMANAGER_CLASS);
    opt->outputScalarManagerClass = cfg->getAsString(CFGID_OUTPUTSCALARMANAGER_CLASS);
    opt->snapshotmanagerClass = cfg->getAsString(CFGID_SNAPSHOTMANAGER_CLASS);

    opt->fnameAppendHost = cfg->getAsBool(CFGID_FNAME_APPEND_HOST, opt->parsim);

    debugOnErrors = cfg->getAsBool(CFGID_DEBUG_ON_ERRORS);
    attachDebuggerOnErrors = cfg->getAsBool(CFGID_DEBUGGER_ATTACH_ON_ERROR);
    opt->printUndisposed = cfg->getAsBool(CFGID_PRINT_UNDISPOSED);

    // simtime resolution
    bool hasSimtimeResolution = cfg->getConfigValue(CFGID_SIMTIME_RESOLUTION->getName()) != nullptr;
    bool hasSimtimeScale = cfg->getConfigValue(CFGID_SIMTIME_SCALE->getName()) != nullptr;
    int exp;
    if (hasSimtimeResolution || !hasSimtimeScale)
        exp = parseSimtimeResolution(cfg->getAsCustom(CFGID_SIMTIME_RESOLUTION)); // new
    else
        exp = (int)cfg->getAsInt(CFGID_SIMTIME_SCALE); // legacy
    SimTime::setScaleExp(exp);
    if (hasSimtimeScale)
        printfmsg("Warning: Obsolete config option %s= found, please use the improved %s= instead "
                "(it allows values like \"us\" or \"100ps\" in addition to base-10 scale exponents)",
                CFGID_SIMTIME_SCALE->getName(), CFGID_SIMTIME_RESOLUTION->getName());

    // note: this is read per run as well, but Tkenv needs its value on startup too
    opt->inifileNetworkDir = cfg->getConfigEntry(CFGID_NETWORK->getName()).getBaseDirectory();

    // path for images and other resources
    std::string imagePath = opp_emptytodefault(getenv("OMNETPP_IMAGE_PATH"), OMNETPP_IMAGE_PATH);
    // strip away the /; sequence from the beginning (a workaround for MinGW path conversion). See #785
    if (imagePath.find("/;") == 0)
        imagePath.erase(0, 2);
    std::string configImagePath = cfg->getAsPath(CFGID_IMAGE_PATH);
    if (!configImagePath.empty())
        imagePath = configImagePath + ";" + imagePath;
    opt->imagePath = imagePath;

    // NED path. It is taken from the "-n" command-line option or the NEDPATH variable
    // ("-n" takes precedence), and the "ned-path=" config entry gets appended to it.
    // If the result is still empty, we fall back to "." -- this is needed for
    // single-directory models to work
    const char *nedPath1 = args->optionValue('n', 0);
    if (!nedPath1)
        nedPath1 = getenv("NEDPATH");
    std::string nedPath2 = getConfig()->getAsPath(CFGID_NED_PATH);
    std::string nedPath = opp_join(";", nedPath1, nedPath2.c_str());
    if (nedPath.empty())
        nedPath = ".";
    opt->nedPath = nedPath;

    // other options are read on per-run basis
}

void EnvirBase::readPerRunOptions()
{
    cConfiguration *cfg = getConfig();

    // get options from ini file
    opt->networkName = cfg->getAsString(CFGID_NETWORK);
    opt->inifileNetworkDir = cfg->getConfigEntry(CFGID_NETWORK->getName()).getBaseDirectory();
    opt->warnings = cfg->getAsBool(CFGID_WARNINGS);
    opt->simtimeLimit = cfg->getAsDouble(CFGID_SIM_TIME_LIMIT);
    opt->cpuTimeLimit = (long)cfg->getAsDouble(CFGID_CPU_TIME_LIMIT);
    opt->warmupPeriod = cfg->getAsDouble(CFGID_WARMUP_PERIOD);
    opt->numRNGs = cfg->getAsInt(CFGID_NUM_RNGS);
    opt->rngClass = cfg->getAsString(CFGID_RNG_CLASS);
    opt->seedset = cfg->getAsInt(CFGID_SEED_SET);
    opt->debugStatisticsRecording = cfg->getAsBool(CFGID_DEBUG_STATISTICS_RECORDING);
    opt->checkSignals = cfg->getAsBool(CFGID_CHECK_SIGNALS);

    getSimulation()->setWarmupPeriod(opt->warmupPeriod);

    // install fingerprint calculator object
    cFingerprintCalculator *fingerprint = nullptr;
    std::string expectedFingerprints = cfg->getAsString(CFGID_FINGERPRINT);
    if (!expectedFingerprints.empty()) {
        // create calculator
#ifdef USE_OMNETPP4x_FINGERPRINTS
        std::string fingerprintClass = "omnetpp::cOmnetpp4xFingerprintCalculator";
        CREATE_BY_CLASSNAME(fingerprint, fingerprintClass.c_str(), cFingerprintCalculator, "fingerprint calculator");
#else
        std::string fingerprintClass = cfg->getAsString(CFGID_FINGERPRINTER_CLASS);
        CREATE_BY_CLASSNAME(fingerprint, fingerprintClass.c_str(), cFingerprintCalculator, "fingerprint calculator");
        if (expectedFingerprints.find(',') != expectedFingerprints.npos)
            fingerprint = new cMultiFingerprintCalculator(fingerprint);
#endif
        fingerprint->initialize(expectedFingerprints.c_str(), cfg);
    }
    getSimulation()->setFingerprintCalculator(fingerprint);

    cComponent::setCheckSignals(opt->checkSignals);

    // run RNG self-test on RNG class selected for this run
    cRNG *testrng;
    CREATE_BY_CLASSNAME(testrng, opt->rngClass.c_str(), cRNG, "random number generator");
    testrng->selfTest();
    delete testrng;

    // set up RNGs
    for (int i = 0; i < numRNGs; i++)
        delete rngs[i];
    delete[] rngs;

    numRNGs = opt->numRNGs;
    rngs = new cRNG *[numRNGs];
    for (int i = 0; i < numRNGs; i++) {
        cRNG *rng;
        CREATE_BY_CLASSNAME(rng, opt->rngClass.c_str(), cRNG, "random number generator");
        rngs[i] = rng;
        rngs[i]->initialize(opt->seedset, i, numRNGs, getParsimProcId(), getParsimNumPartitions(), getConfig());
    }

    // init nextUniqueNumber -- startRun() is too late because simple module ctors have run by then
    nextUniqueNumber = 0;
#ifdef WITH_PARSIM
    if (opt->parsim)
        nextUniqueNumber = (unsigned)parsimComm->getProcId() * ((~0UL) / (unsigned)parsimComm->getNumPartitions());
#endif

    // open eventlog file.
    recordEventlog = cfg->getAsBool(CFGID_RECORD_EVENTLOG);
}

int EnvirBase::parseSimtimeResolution(const char *resolution)
{
    try {
        // Three possibilities: <unit-only>, <number-with-unit>, <number-only>
        const double INVALID_EXP = 1e100;
        double exp = INVALID_EXP;
        if (opp_isalpha(resolution[0])) {
            // try as <unit-only>, e.g. "ms"
            double f = UnitConversion::getConversionFactor(resolution, "s");
            if (f == 0)
                throw std::runtime_error("wrong unit");
            exp = log10(f);
            ASSERT(exp == floor(exp));
        }
        else {
            // try as <number-only>: this will be an exponent, e.g. -12
            try { exp = opp_atol(resolution); } catch (std::exception& e) {}

            // try as <number-with-unit>, e.g. "100ps"
            if (exp == INVALID_EXP) {
                double f = UnitConversion::parseQuantity(resolution, "s");
                exp = log10(f);
                if (exp != floor(exp))
                    throw std::runtime_error("not power of 10");
            }
        }
        return (int)exp;
    }
    catch (std::exception& e) {
        throw cRuntimeError(
                "Invalid value \"%s\" for configuration option simtime-resolution: it must be "
                "a valid second-or-smaller time unit (s, ms, us, ns, ps, fs or as), "
                "a power-of-ten multiple of such unit (e.g. 100ms), or a base-10 scale "
                "exponent in the -18..0 range. (Details: %s)", resolution, e.what());
    }
}

void EnvirBase::setEventlogRecording(bool enabled)
{
    if (enabled != recordEventlog) {
        // NOTE: eventlogmgr must be non-nullptr when record_eventlog is true
        if (enabled)
            eventlogManager->startRecording();
        else
            eventlogManager->stopRecording();
        recordEventlog = enabled;
    }
}

void EnvirBase::setLogLevel(LogLevel logLevel)
{
    cLog::logLevel = logLevel;
}

void EnvirBase::setLogFormat(const char *logFormat)
{
    logFormatter.setFormat(logFormat);
    logFormatUsesEventName = logFormatter.usesEventName();
}

//-------------------------------------------------------------

int EnvirBase::getNumRNGs() const
{
    return numRNGs;
}

cRNG *EnvirBase::getRNG(int k)
{
    if (k < 0 || k >= numRNGs)
        throw cRuntimeError("RNG index %d is out of range (num-rngs=%d, check the configuration)", k, numRNGs);
    return rngs[k];
}

void EnvirBase::setupRNGMapping(cComponent *component)
{
    cConfigurationEx *cfg = getConfigEx();
    std::string componentFullPath = component->getFullPath();
    std::vector<const char *> suffixes = cfg->getMatchingPerObjectConfigKeySuffixes(componentFullPath.c_str(), "rng-*");  // CFGID_RNG_K
    if (suffixes.empty())
        return;

    // extract into tmpmap[]
    int mapsize = 0;
    int tmpmap[100];
    for (int i = 0; i < (int)suffixes.size(); i++) {
        const char *suffix = suffixes[i];  // contains "rng-1", "rng-4" or whichever has been found in the config for this module/channel
        const char *value = cfg->getPerObjectConfigValue(componentFullPath.c_str(), suffix);
        ASSERT(value != nullptr);
        try {
            char *endptr;
            int modRng = strtol(suffix+strlen("rng-"), &endptr, 10);
            if (*endptr != '\0')
                throw opp_runtime_error("numeric RNG indices expected");

            int physRng = strtol(value, &endptr, 10);
            if (*endptr != '\0') {
                // not a numeric constant, try parsing it as an expression
                cDynamicExpression expr;
                expr.parse(value);
                cNEDValue tmp = expr.evaluate(component);
                if (!tmp.isNumeric())
                    throw opp_runtime_error("numeric constant or expression expected");
                physRng = tmp.longValue();
            }

            if (physRng >= getNumRNGs())
                throw cRuntimeError("RNG index %d out of range (num-rngs=%d)", physRng, getNumRNGs());
            if (modRng >= mapsize) {
                if (modRng >= 100)
                    throw cRuntimeError("local RNG index %d out of supported range 0..99", modRng);
                while (mapsize <= modRng) {
                    tmpmap[mapsize] = mapsize;
                    mapsize++;
                }
            }
            tmpmap[modRng] = physRng;
        }
        catch (std::exception& e) {
            throw cRuntimeError("configuration entry *.%s = %s for module/channel %s: %s",
                    suffix, value, component->getFullPath().c_str(), e.what());

        }
    }

    // install map into the module
    if (mapsize > 0) {
        int *map = new int[mapsize];
        memcpy(map, tmpmap, mapsize*sizeof(int));
        component->setRNGMap(mapsize, map);
    }
}

//-------------------------------------------------------------

void *EnvirBase::registerOutputVector(const char *modulename, const char *vectorname)
{
    assert(outvectorManager);
    return outvectorManager->registerVector(modulename, vectorname);
}

void EnvirBase::deregisterOutputVector(void *vechandle)
{
    assert(outvectorManager);
    outvectorManager->deregisterVector(vechandle);
}

void EnvirBase::setVectorAttribute(void *vechandle, const char *name, const char *value)
{
    assert(outvectorManager);
    outvectorManager->setVectorAttribute(vechandle, name, value);
}

bool EnvirBase::recordInOutputVector(void *vechandle, simtime_t t, double value)
{
    assert(outvectorManager);
    if (getSimulation()->getFingerprintCalculator())
        // TODO: determine component and result name if possible
        getSimulation()->getFingerprintCalculator()->addVectorResult(nullptr, "", t, value);
    return outvectorManager->record(vechandle, t, value);
}

//-------------------------------------------------------------

void EnvirBase::recordScalar(cComponent *component, const char *name, double value, opp_string_map *attributes)
{
    assert(outScalarManager);
    outScalarManager->recordScalar(component, name, value, attributes);
    if (getSimulation()->getFingerprintCalculator())
        getSimulation()->getFingerprintCalculator()->addScalarResult(component, name, value);
}

void EnvirBase::recordStatistic(cComponent *component, const char *name, cStatistic *statistic, opp_string_map *attributes)
{
    assert(outScalarManager);
    outScalarManager->recordStatistic(component, name, statistic, attributes);
    if (getSimulation()->getFingerprintCalculator())
        getSimulation()->getFingerprintCalculator()->addStatisticResult(component, name, statistic);
}

//-------------------------------------------------------------

std::ostream *EnvirBase::getStreamForSnapshot()
{
    return snapshotManager->getStreamForSnapshot();
}

void EnvirBase::releaseStreamForSnapshot(std::ostream *os)
{
    snapshotManager->releaseStreamForSnapshot(os);
}

//-------------------------------------------------------------

unsigned long EnvirBase::getUniqueNumber()
{
    unsigned long ret = nextUniqueNumber++;
    if (nextUniqueNumber == 0)
        throw cRuntimeError("getUniqueNumber(): all values have been consumed");
#ifdef WITH_PARSIM
    if (opt->parsim) {
        unsigned long limit = (unsigned)(parsimComm->getProcId()+1) * ((~0UL) / (unsigned)parsimComm->getNumPartitions());
        if (nextUniqueNumber == limit)
            throw cRuntimeError("getUniqueNumber(): all values have been consumed");
    }
#endif
    return ret;
}

std::string EnvirBase::makeDebuggerCommand()
{
    std::string cmd = getConfig()->getAsString(CFGID_DEBUGGER_ATTACH_COMMAND);
    if (cmd == "") {
        ::printf("Cannot start debugger: no debugger configured\n");
        return "";
    }
    size_t pos = cmd.find('%');
    if (pos == std::string::npos || cmd.rfind('%') != pos || cmd[pos+1] != 'u') {
        ::printf("Cannot start debugger: debugger attach command must contain '%%u' "
                 "and no additional percent sign.\n");
        return "";
    }
    pid_t pid = getpid();
    return opp_stringf(cmd.c_str(), (unsigned int)pid);
}

void EnvirBase::attachDebugger()
{
    // launch debugger
    std::string cmd = makeDebuggerCommand();
    if (cmd == "")
        return;  // no suitable debugger command

    ::printf("Starting debugger: %s\n", cmd.c_str());
    fflush(stdout);
    system(cmd.c_str());

    ::printf("Waiting for the debugger to start up and attach to us; note that "
             "for the latter to work, some systems (e.g. Ubuntu) require debugging "
             "of non-child processes to be explicitly enabled.\n");
    fflush(stdout);

    // hold for a while to allow debugger to start up and attach to us
    int secondsToWait = (int)ceil(getConfig()->getAsDouble(CFGID_DEBUGGER_ATTACH_WAIT_TIME));
    time_t startTime = time(nullptr);
    while (time(nullptr)-startTime < secondsToWait)
        for (int i=0; i<1000; i++); // DEBUGGER ATTACHED -- YOUR CODE IS A FEW FRAMES UP ON THE CALL STACK
}

void EnvirBase::crashHandler(int)
{
    cSimulation::getActiveEnvir()->attachDebugger();
}

void EnvirBase::displayException(std::exception& ex)
{
    cException *e = dynamic_cast<cException *>(&ex);
    if (!e)
        printfmsg("Error: %s.", ex.what());
    else
        printfmsg("%s", e->getFormattedMessage().c_str());
}

bool EnvirBase::idle()
{
    return false;
}

int EnvirBase::getArgCount() const
{
    return args->getArgCount();
}

char **EnvirBase::getArgVector() const
{
    return args->getArgVector();
}

void EnvirBase::addLifecycleListener(cISimulationLifecycleListener *listener)
{
    std::vector<cISimulationLifecycleListener *>::iterator it = std::find(listeners.begin(), listeners.end(), listener);
    if (it == listeners.end()) {
        listeners.push_back(listener);
        listener->listenerAdded();
    }
}

void EnvirBase::removeLifecycleListener(cISimulationLifecycleListener *listener)
{
    std::vector<cISimulationLifecycleListener *>::iterator it = std::find(listeners.begin(), listeners.end(), listener);
    if (it != listeners.end()) {
        listeners.erase(it);
        listener->listenerRemoved();
    }
}

void EnvirBase::notifyLifecycleListeners(SimulationLifecycleEventType eventType, cObject *details)
{
    // make a copy of the listener list, to avoid problems from listeners
    // getting added/removed during notification
    std::vector<cISimulationLifecycleListener *> copy = listeners;
    for (int i = 0; i < (int)copy.size(); i++) {
        try {
            copy[i]->lifecycleEvent(eventType, details);
        }
        catch (std::exception& e) {  // XXX perhaps we shouldn't hide the exception!!!! just re-throw? then all notifyLifecycleListeners() calls MUST be surrounded with try-catch!!!!
            // XXX const char *eventName = cISimulationLifecycleListener::getSimulationLifecycleEventName(eventType);
            // XXX printfmsg("Error in %s listener: %s", eventName, e.what());
            displayException(e);
        }
    }
}

//-------------------------------------------------------------

void EnvirBase::resetClock()
{
    timeval now;
    gettimeofday(&now, nullptr);
    lastStarted = simEndTime = simBegTime = now;
    elapsedTime.tv_sec = elapsedTime.tv_usec = 0;
}

void EnvirBase::startClock()
{
    gettimeofday(&lastStarted, nullptr);
}

void EnvirBase::stopClock()
{
    gettimeofday(&simEndTime, nullptr);
    elapsedTime = elapsedTime + simEndTime - lastStarted;
    simulatedTime = getSimulation()->getSimTime();
}

timeval EnvirBase::totalElapsed()
{
    timeval now;
    gettimeofday(&now, nullptr);
    return now - lastStarted + elapsedTime;
}

void EnvirBase::checkTimeLimits()
{
#ifdef USE_OMNETPP4x_FINGERPRINTS
    if (opt->simtimeLimit != SIMTIME_ZERO && getSimulation()->getSimTime() >= opt->simtimeLimit)
        throw cTerminationException(E_SIMTIME);
#endif
    if (opt->cpuTimeLimit == 0)  // no limit
        return;
    if (isExpressMode() && (getSimulation()->getEventNumber()&0xFF) != 0)  // optimize: in Express mode, don't call gettimeofday() on every event
        return;
    timeval now;
    gettimeofday(&now, nullptr);
    long elapsedsecs = now.tv_sec - lastStarted.tv_sec + elapsedTime.tv_sec;
    if (elapsedsecs >= opt->cpuTimeLimit)
        throw cTerminationException(E_REALTIME);
}

void EnvirBase::stoppedWithTerminationException(cTerminationException& e)
{
    // if we're running in parallel and this exception is NOT one we received
    // from other partitions, then notify other partitions
#ifdef WITH_PARSIM
    if (opt->parsim && !dynamic_cast<cReceivedTerminationException *>(&e))
        parsimPartition->broadcastTerminationException(e);
#endif
    if (recordEventlog)
        eventlogManager->stoppedWithException(e.isError(), e.getErrorCode(), e.getFormattedMessage().c_str());
}

void EnvirBase::stoppedWithException(std::exception& e)
{
    // if we're running in parallel and this exception is NOT one we received
    // from other partitions, then notify other partitions
#ifdef WITH_PARSIM
    if (opt->parsim && !dynamic_cast<cReceivedException *>(&e))
        parsimPartition->broadcastException(e);
#endif
    if (recordEventlog)
        // TODO: get error code from the exception?
        eventlogManager->stoppedWithException(true, E_CUSTOM, e.what());
}

void EnvirBase::checkFingerprint()
{
    cFingerprintCalculator *fingerprint = getSimulation()->getFingerprintCalculator();
    if (!getSimulation()->getFingerprintCalculator())
        return;

    if (fingerprint->checkFingerprint())
        printfmsg("Fingerprint successfully verified: %s", fingerprint->info().c_str());
    else
        printfmsg("Fingerprint mismatch! calculated: %s, expected: %s",
                fingerprint->info().c_str(), cfg->getAsString(CFGID_FINGERPRINT).c_str());
}

cModuleType *EnvirBase::resolveNetwork(const char *networkname)
{
    cModuleType *network = nullptr;
    std::string inifilePackage = getSimulation()->getNedPackageForFolder(opt->inifileNetworkDir.c_str());

    bool hasInifilePackage = !inifilePackage.empty() && strcmp(inifilePackage.c_str(), "-") != 0;
    if (hasInifilePackage)
        network = cModuleType::find((inifilePackage+"."+networkname).c_str());
    if (!network)
        network = cModuleType::find(networkname);
    if (!network) {
        if (hasInifilePackage)
            throw cRuntimeError("Network `%s' or `%s' not found, check .ini and .ned files",
                    networkname, (inifilePackage+"."+networkname).c_str());
        else
            throw cRuntimeError("Network `%s' not found, check .ini and .ned files", networkname);
    }
    if (!network->isNetwork())
        throw cRuntimeError("Module type `%s' is not a network", network->getFullName());
    return network;
}

}  // namespace envir
}  // namespace omnetpp

