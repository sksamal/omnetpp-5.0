//==========================================================================
//  FILEOUTPUTSCALARMGR.CC - part of
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
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

#include "omnetpp/simkerneldefs.h"

#include <cassert>
#include <cstring>
#include <fstream>
#include <clocale>
#include "common/opp_ctype.h"
#include "common/fileutil.h"
#include "common/stringutil.h"
#include "common/unitconversion.h"
#include "omnetpp/cconfigoption.h"
#include "omnetpp/csimulation.h"
#include "omnetpp/cmodule.h"
#include "omnetpp/cstatistic.h"
#include "omnetpp/cdensityestbase.h"
#include "omnetpp/ccomponenttype.h"
#include "envirbase.h"
#include "fileoutscalarmgr.h"

using namespace omnetpp::common;

namespace omnetpp {
namespace envir {

#define SCALAR_FILE_VERSION    2
#define DEFAULT_PRECISION      "14"

Register_PerRunConfigOption(CFGID_OUTPUT_SCALAR_FILE, "output-scalar-file", CFG_FILENAME, "${resultdir}/${configname}-${runnumber}.sca", "Name for the output scalar file.");
Register_PerRunConfigOption(CFGID_OUTPUT_SCALAR_PRECISION, "output-scalar-precision", CFG_INT, DEFAULT_PRECISION, "The number of significant digits for recording data into the output scalar file. The maximum value is ~15 (IEEE double precision).");
Register_PerRunConfigOption(CFGID_OUTPUT_SCALAR_FILE_APPEND, "output-scalar-file-append", CFG_BOOL, "false", "What to do when the output scalar file already exists: append to it (OMNeT++ 3.x behavior), or delete it and begin a new file (default).");

Register_PerObjectConfigOption(CFGID_SCALAR_RECORDING, "scalar-recording", KIND_SCALAR, CFG_BOOL, "true", "Whether the matching output scalars and statistic objects should be recorded.\nUsage: `<module-full-path>.<scalar-name>.scalar-recording=true/false`. To enable/disable individual recording modes for a @statistic (those added via the `record=...` key of `@statistic` or the `**.result-recording-modes=...` config option), use `<statistic-name>:<mode>` for `<scalar-name>`, and make sure the `@statistic` as a whole is not disabled with `**.<statistic-name>.statistic-recording=false`.\nExample: `**.ping.roundTripTime:stddev.scalar-recording=false`");
Register_PerObjectConfigOption(CFGID_BIN_RECORDING, "bin-recording", KIND_SCALAR, CFG_BOOL, "true", "Whether the bins of the matching histogram object should be recorded, provided that recording of the histogram object itself is enabled (`**.<scalar-name>.scalar-recording=true`).\nUsage: `<module-full-path>.<scalar-name>.bin-recording=true/false`. To control histogram recording from a `@statistic`, use `<statistic-name>:histogram` for `<scalar-name>`.\nExample: `**.ping.roundTripTime:histogram.bin-recording=false`");

Register_Class(cFileOutputScalarManager);

#ifdef CHECK
#undef CHECK
#endif
#define CHECK(fprintf)    if (fprintf<0) throw cRuntimeError("Cannot write output scalar file `%s'", fname.c_str())


cFileOutputScalarManager::cFileOutputScalarManager()
{
    f = nullptr;
    prec = getEnvir()->getConfig()->getAsInt(CFGID_OUTPUT_SCALAR_PRECISION);
}

cFileOutputScalarManager::~cFileOutputScalarManager()
{
    closeFile();
}

void cFileOutputScalarManager::openFile()
{
    mkPath(directoryOf(fname.c_str()).c_str());
    f = fopen(fname.c_str(), "a");
    if (f == nullptr)
        throw cRuntimeError("Cannot open output scalar file `%s'", fname.c_str());
}

void cFileOutputScalarManager::closeFile()
{
    if (f) {
        fclose(f);
        f = nullptr;
    }
}

void cFileOutputScalarManager::startRun()
{
    // clean up file from previous runs
    closeFile();
    fname = getEnvir()->getConfig()->getAsFilename(CFGID_OUTPUT_SCALAR_FILE);
    dynamic_cast<EnvirBase *>(getEnvir())->processFileName(fname);
    if (getEnvir()->getConfig()->getAsBool(CFGID_OUTPUT_SCALAR_FILE_APPEND) == false)
        removeFile(fname.c_str(), "old output scalar file");
    run.reset();
}

void cFileOutputScalarManager::endRun()
{
    closeFile();
}

void cFileOutputScalarManager::init()
{
    if (!f) {
        openFile();
        if (!f)
            return;

        CHECK(fprintf(f, "version %d\n", SCALAR_FILE_VERSION));
    }

    if (!run.initialized) {
        run.initRun();

        // this is the first scalar written in this run, write out run attributes
        run.writeRunData(f, fname);

        // save iteration variables
        std::vector<const char *> v = getEnvir()->getConfigEx()->getIterationVariableNames();
        for (int i = 0; i < (int)v.size(); i++) {
            const char *name = v[i];
            const char *value = getEnvir()->getConfigEx()->getVariable(v[i]);
            recordNumericIterationVariable(name, value);
        }
    }
}

void cFileOutputScalarManager::recordNumericIterationVariable(const char *name, const char *value)
{
    char *e;
    setlocale(LC_NUMERIC, "C");
    (void)strtod(value, &e);
    if (*e == '\0') {
        // plain number - just record as it is
        // XXX write with using an "itervar" keyword not "scalar" (needs to be understood by IDE as well)
        CHECK(fprintf(f, "scalar . \t%s \t%s\n", name, value));
    }
    else if (e != value) {
        // starts with a number, so it might be something like "100s"; if so, record it as scalar with "unit" attribute
        double d;
        std::string unit;
        bool parsedOK = false;
        try {
            d = UnitConversion::parseQuantity(value, unit);
            parsedOK = true;
        }
        catch (std::exception& e) {
        }
        if (parsedOK) {
            CHECK(fprintf(f, "scalar . \t%s \t%.*g\n", name, prec, d));
            if (!unit.empty())
                CHECK(fprintf(f, "attr unit  %s\n", QUOTE(unit.c_str())));
        }
    }
}

void cFileOutputScalarManager::recordScalar(cComponent *component, const char *name, double value, opp_string_map *attributes)
{
    if (!run.initialized)
        init();
    if (!f)
        return;

    if (!name || !name[0])
        name = "(unnamed)";

    bool enabled = getEnvir()->getConfig()->getAsBool((component->getFullPath()+"."+name).c_str(), CFGID_SCALAR_RECORDING);
    if (enabled) {
        CHECK(fprintf(f, "scalar %s \t%s \t%.*g\n", QUOTE(component->getFullPath().c_str()), QUOTE(name), prec, value));
        if (attributes)
            for (opp_string_map::iterator it = attributes->begin(); it != attributes->end(); ++it)
                CHECK(fprintf(f, "attr %s  %s\n", QUOTE(it->first.c_str()), QUOTE(it->second.c_str())));

    }
}

void cFileOutputScalarManager::recordStatistic(cComponent *component, const char *name, cStatistic *statistic, opp_string_map *attributes)
{
    if (!run.initialized)
        init();
    if (!f)
        return;

    if (!name)
        name = statistic->getFullName();
    if (!name || !name[0])
        name = "(unnamed)";

    // check that recording this statistic object is not disabled
    std::string objectFullPath = component->getFullPath() + "." + name;
    bool enabled = getEnvir()->getConfig()->getAsBool(objectFullPath.c_str(), CFGID_SCALAR_RECORDING);
    if (!enabled)
        return;

    // file format:
    //   statistic <modulepath> <statisticname>
    //   field count 343
    //   field weights 343
    //   field mean    2.1233
    //   field stddev  1.345
    //   attr unit s
    //   bin 0  3
    //   bin 10 13
    //   bin 20 19
    //   ...
    // In Scave, fields are read as separate scalars.
    CHECK(fprintf(f, "statistic %s \t%s\n", QUOTE(component->getFullPath().c_str()), QUOTE(name)));
    writeStatisticField("count", statistic->getCount());
    writeStatisticField("mean", statistic->getMean());
    writeStatisticField("stddev", statistic->getStddev());
    writeStatisticField("sum", statistic->getSum());
    writeStatisticField("sqrsum", statistic->getSqrSum());
    writeStatisticField("min", statistic->getMin());
    writeStatisticField("max", statistic->getMax());
    if (statistic->isWeighted()) {
        writeStatisticField("weights", statistic->getWeights());
        writeStatisticField("weightedSum", statistic->getWeightedSum());
        writeStatisticField("sqrSumWeights", statistic->getSqrSumWeights());
        writeStatisticField("weightedSqrSum", statistic->getWeightedSqrSum());
    }

    if (attributes)
        for (opp_string_map::iterator it = attributes->begin(); it != attributes->end(); ++it)
            CHECK(fprintf(f, "attr %s  %s\n", QUOTE(it->first.c_str()), QUOTE(it->second.c_str())));


    if (cDensityEstBase *histogram = dynamic_cast<cDensityEstBase *>(statistic)) {
        // check that recording histogram bins is enabled
        bool binsEnabled = getEnvir()->getConfig()->getAsBool(objectFullPath.c_str(), CFGID_BIN_RECORDING);
        if (binsEnabled) {
            if (!histogram->isTransformed())
                histogram->transform();

            int n = histogram->getNumCells();
            if (n > 0) {
                CHECK(fprintf(f, "bin\t-INF\t%lu\n", histogram->getUnderflowCell()));
                for (int i = 0; i < n; i++)
                    CHECK(fprintf(f, "bin\t%.*g\t%.*g\n", prec, histogram->getBasepoint(i), prec, histogram->getCellValue(i)));
                CHECK(fprintf(f, "bin\t%.*g\t%lu\n", prec, histogram->getBasepoint(n), histogram->getOverflowCell()));
            }
        }
    }
}

void cFileOutputScalarManager::writeStatisticField(const char *name, long value)
{
    if (fprintf(f, "field %s %ld\n", QUOTE(name), value) < 0)
        throw cRuntimeError("Cannot write output scalar file `%s'", fname.c_str());
}

void cFileOutputScalarManager::writeStatisticField(const char *name, double value)
{
    if (fprintf(f, "field %s %.*g\n", QUOTE(name), prec, value) < 0)
        throw cRuntimeError("Cannot write output scalar file `%s'", fname.c_str());
}

const char *cFileOutputScalarManager::getFileName() const
{
    return fname.c_str();
}

void cFileOutputScalarManager::flush()
{
    if (f)
        fflush(f);
}

}  // namespace envir
}  // namespace omnetpp

