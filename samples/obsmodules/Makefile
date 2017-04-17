#
# OMNeT++/OMNEST Makefile for obsmodules
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../inet/src -I../inet/src/inet/networklayer/contract/ipv4 -I../inet/src/inet/networklayer/ipv4 -I../inet/src/inet/transportlayer/tcp_common -I../inet/src/inet/transportlayer/udp -I../inet/src/inet/common -I../inet/src/inet/networklayer/contract -L../inet/out/$$\(CONFIGNAME\)/src -lINET -KINET_PROJ=../inet
#

# Name of target to be created (-o option)
TARGET = obsmodules$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../inet/src \
    -I../inet/src/inet/networklayer/contract/ipv4 \
    -I../inet/src/inet/networklayer/ipv4 \
    -I../inet/src/inet/transportlayer/tcp_common \
    -I../inet/src/inet/transportlayer/udp \
    -I../inet/src/inet/common \
    -I../inet/src/inet/networklayer/contract \
    -I. \
    -IExamples \
    -IExamples/BurstifierTest \
    -IExamples/BurstifierTest/results \
    -IExamples/DispatcherTest \
    -IExamples/EdgeNodeExample \
    -IExamples/EdgeNodeTest \
    -IExamples/TreeTopologyOBS \
    -IExamples/jitel09 \
    -Idoc \
    -Idoc/img \
    -Isrc \
    -Isrc/CoreNode \
    -Isrc/EdgeNode \
    -Isrc/messages \
    -Isrc/misc \
    -Isrc/tests \
    -Isrc/tests/sinks \
    -Isrc/tests/sources \
    -Itest \
    -Itest/BurstDisassemblerTest \
    -Itest/BurstDisassemblerTest/results \
    -Itest/BurstSenderTest \
    -Itest/BurstSenderTest/results \
    -Itest/CoreInputTest \
    -Itest/CoreNodeTest \
    -Itest/CoreOutputTest \
    -Itest/DropBurstTest \
    -Itest/EOConverterTest \
    -Itest/FileBurstifierTest \
    -Itest/OEConverterTest \
    -Itest/OpticalMonitorTest \
    -Itest/PacketBurstifierTest \
    -Itest/PacketBurstifierTest/results \
    -Itest/PacketDispatcherTest \
    -Iutils

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../inet/out/$(CONFIGNAME)/src  -lINET
LIBS += -Wl,-rpath,`abspath ../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/src/CoreNode/OBS_CoreInput.o \
    $O/src/CoreNode/OBS_EOConverter.o \
    $O/src/CoreNode/OBS_CoreOutput.o \
    $O/src/CoreNode/OBS_CoreControlLogic.o \
    $O/src/CoreNode/OBS_CoreOutputHorizon.o \
    $O/src/CoreNode/OBS_CoreRoutingTable.o \
    $O/src/CoreNode/OBS_OpticalCrossConnect.o \
    $O/src/CoreNode/OBS_OEConverter.o \
    $O/src/EdgeNode/OBS_DispatcherRule.o \
    $O/src/EdgeNode/OBS_FileBurstifier.o \
    $O/src/EdgeNode/OBS_BurstDisassembler.o \
    $O/src/EdgeNode/OBS_BurstSender.o \
    $O/src/EdgeNode/BurstList.o \
    $O/src/EdgeNode/OBS_PacketBurstifier.o \
    $O/src/EdgeNode/OBS_PacketDispatcher.o \
    $O/src/messages/OBS_Burst.o \
    $O/src/misc/OBS_OpticalMonitor.o \
    $O/src/misc/OBS_DropBurst.o \
    $O/src/tests/PacketConverter.o \
    $O/src/tests/sinks/testSink2.o \
    $O/src/tests/sinks/testSink3.o \
    $O/src/tests/sinks/testSink5.o \
    $O/src/tests/sinks/testSink1.o \
    $O/src/tests/sinks/testSink4.o \
    $O/src/tests/sources/testSource4.o \
    $O/src/tests/sources/testSource3.o \
    $O/src/tests/sources/testSource5.o \
    $O/src/tests/sources/testSource2.o \
    $O/src/tests/sources/testSource1.o \
    $O/src/CoreNode/OBS_ControlUnitInfo_m.o \
    $O/src/CoreNode/OBS_BCPControlInfo_m.o \
    $O/src/CoreNode/OBS_CoreRoutingTableEntry_m.o \
    $O/src/EdgeNode/OBS_BurstifierInfo_m.o \
    $O/src/EdgeNode/OBS_ScheduledBurstItem_m.o \
    $O/src/EdgeNode/OBS_BurstSenderInfo_m.o \
    $O/src/messages/OBS_BurstControlPacket_m.o \
    $O/src/messages/OBS_Burst_m.o \
    $O/src/tests/sources/SourceControlInfo_m.o

# Message files
MSGFILES = \
    src/CoreNode/OBS_ControlUnitInfo.msg \
    src/CoreNode/OBS_BCPControlInfo.msg \
    src/CoreNode/OBS_CoreRoutingTableEntry.msg \
    src/EdgeNode/OBS_BurstifierInfo.msg \
    src/EdgeNode/OBS_ScheduledBurstItem.msg \
    src/EdgeNode/OBS_BurstSenderInfo.msg \
    src/messages/OBS_BurstControlPacket.msg \
    src/messages/OBS_Burst.msg \
    src/tests/sources/SourceControlInfo.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f obsmodules obsmodules.exe libobsmodules.so libobsmodules.a libobsmodules.dll libobsmodules.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h ./*_sm.cc ./*_sm.h
	$(Q)-rm -f Examples/*_m.cc Examples/*_m.h Examples/*_sm.cc Examples/*_sm.h
	$(Q)-rm -f Examples/BurstifierTest/*_m.cc Examples/BurstifierTest/*_m.h Examples/BurstifierTest/*_sm.cc Examples/BurstifierTest/*_sm.h
	$(Q)-rm -f Examples/BurstifierTest/results/*_m.cc Examples/BurstifierTest/results/*_m.h Examples/BurstifierTest/results/*_sm.cc Examples/BurstifierTest/results/*_sm.h
	$(Q)-rm -f Examples/DispatcherTest/*_m.cc Examples/DispatcherTest/*_m.h Examples/DispatcherTest/*_sm.cc Examples/DispatcherTest/*_sm.h
	$(Q)-rm -f Examples/EdgeNodeExample/*_m.cc Examples/EdgeNodeExample/*_m.h Examples/EdgeNodeExample/*_sm.cc Examples/EdgeNodeExample/*_sm.h
	$(Q)-rm -f Examples/EdgeNodeTest/*_m.cc Examples/EdgeNodeTest/*_m.h Examples/EdgeNodeTest/*_sm.cc Examples/EdgeNodeTest/*_sm.h
	$(Q)-rm -f Examples/TreeTopologyOBS/*_m.cc Examples/TreeTopologyOBS/*_m.h Examples/TreeTopologyOBS/*_sm.cc Examples/TreeTopologyOBS/*_sm.h
	$(Q)-rm -f Examples/jitel09/*_m.cc Examples/jitel09/*_m.h Examples/jitel09/*_sm.cc Examples/jitel09/*_sm.h
	$(Q)-rm -f doc/*_m.cc doc/*_m.h doc/*_sm.cc doc/*_sm.h
	$(Q)-rm -f doc/img/*_m.cc doc/img/*_m.h doc/img/*_sm.cc doc/img/*_sm.h
	$(Q)-rm -f src/*_m.cc src/*_m.h src/*_sm.cc src/*_sm.h
	$(Q)-rm -f src/CoreNode/*_m.cc src/CoreNode/*_m.h src/CoreNode/*_sm.cc src/CoreNode/*_sm.h
	$(Q)-rm -f src/EdgeNode/*_m.cc src/EdgeNode/*_m.h src/EdgeNode/*_sm.cc src/EdgeNode/*_sm.h
	$(Q)-rm -f src/messages/*_m.cc src/messages/*_m.h src/messages/*_sm.cc src/messages/*_sm.h
	$(Q)-rm -f src/misc/*_m.cc src/misc/*_m.h src/misc/*_sm.cc src/misc/*_sm.h
	$(Q)-rm -f src/tests/*_m.cc src/tests/*_m.h src/tests/*_sm.cc src/tests/*_sm.h
	$(Q)-rm -f src/tests/sinks/*_m.cc src/tests/sinks/*_m.h src/tests/sinks/*_sm.cc src/tests/sinks/*_sm.h
	$(Q)-rm -f src/tests/sources/*_m.cc src/tests/sources/*_m.h src/tests/sources/*_sm.cc src/tests/sources/*_sm.h
	$(Q)-rm -f test/*_m.cc test/*_m.h test/*_sm.cc test/*_sm.h
	$(Q)-rm -f test/BurstDisassemblerTest/*_m.cc test/BurstDisassemblerTest/*_m.h test/BurstDisassemblerTest/*_sm.cc test/BurstDisassemblerTest/*_sm.h
	$(Q)-rm -f test/BurstDisassemblerTest/results/*_m.cc test/BurstDisassemblerTest/results/*_m.h test/BurstDisassemblerTest/results/*_sm.cc test/BurstDisassemblerTest/results/*_sm.h
	$(Q)-rm -f test/BurstSenderTest/*_m.cc test/BurstSenderTest/*_m.h test/BurstSenderTest/*_sm.cc test/BurstSenderTest/*_sm.h
	$(Q)-rm -f test/BurstSenderTest/results/*_m.cc test/BurstSenderTest/results/*_m.h test/BurstSenderTest/results/*_sm.cc test/BurstSenderTest/results/*_sm.h
	$(Q)-rm -f test/CoreInputTest/*_m.cc test/CoreInputTest/*_m.h test/CoreInputTest/*_sm.cc test/CoreInputTest/*_sm.h
	$(Q)-rm -f test/CoreNodeTest/*_m.cc test/CoreNodeTest/*_m.h test/CoreNodeTest/*_sm.cc test/CoreNodeTest/*_sm.h
	$(Q)-rm -f test/CoreOutputTest/*_m.cc test/CoreOutputTest/*_m.h test/CoreOutputTest/*_sm.cc test/CoreOutputTest/*_sm.h
	$(Q)-rm -f test/DropBurstTest/*_m.cc test/DropBurstTest/*_m.h test/DropBurstTest/*_sm.cc test/DropBurstTest/*_sm.h
	$(Q)-rm -f test/EOConverterTest/*_m.cc test/EOConverterTest/*_m.h test/EOConverterTest/*_sm.cc test/EOConverterTest/*_sm.h
	$(Q)-rm -f test/FileBurstifierTest/*_m.cc test/FileBurstifierTest/*_m.h test/FileBurstifierTest/*_sm.cc test/FileBurstifierTest/*_sm.h
	$(Q)-rm -f test/OEConverterTest/*_m.cc test/OEConverterTest/*_m.h test/OEConverterTest/*_sm.cc test/OEConverterTest/*_sm.h
	$(Q)-rm -f test/OpticalMonitorTest/*_m.cc test/OpticalMonitorTest/*_m.h test/OpticalMonitorTest/*_sm.cc test/OpticalMonitorTest/*_sm.h
	$(Q)-rm -f test/PacketBurstifierTest/*_m.cc test/PacketBurstifierTest/*_m.h test/PacketBurstifierTest/*_sm.cc test/PacketBurstifierTest/*_sm.h
	$(Q)-rm -f test/PacketBurstifierTest/results/*_m.cc test/PacketBurstifierTest/results/*_m.h test/PacketBurstifierTest/results/*_sm.cc test/PacketBurstifierTest/results/*_sm.h
	$(Q)-rm -f test/PacketDispatcherTest/*_m.cc test/PacketDispatcherTest/*_m.h test/PacketDispatcherTest/*_sm.cc test/PacketDispatcherTest/*_sm.h
	$(Q)-rm -f utils/*_m.cc utils/*_m.h utils/*_sm.cc utils/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc Examples/*.cc Examples/BurstifierTest/*.cc Examples/BurstifierTest/results/*.cc Examples/DispatcherTest/*.cc Examples/EdgeNodeExample/*.cc Examples/EdgeNodeTest/*.cc Examples/TreeTopologyOBS/*.cc Examples/jitel09/*.cc doc/*.cc doc/img/*.cc src/*.cc src/CoreNode/*.cc src/EdgeNode/*.cc src/messages/*.cc src/misc/*.cc src/tests/*.cc src/tests/sinks/*.cc src/tests/sources/*.cc test/*.cc test/BurstDisassemblerTest/*.cc test/BurstDisassemblerTest/results/*.cc test/BurstSenderTest/*.cc test/BurstSenderTest/results/*.cc test/CoreInputTest/*.cc test/CoreNodeTest/*.cc test/CoreOutputTest/*.cc test/DropBurstTest/*.cc test/EOConverterTest/*.cc test/FileBurstifierTest/*.cc test/OEConverterTest/*.cc test/OpticalMonitorTest/*.cc test/PacketBurstifierTest/*.cc test/PacketBurstifierTest/results/*.cc test/PacketDispatcherTest/*.cc utils/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/CoreNode/OBS_BCPControlInfo_m.o: src/CoreNode/OBS_BCPControlInfo_m.cc \
	src/CoreNode/OBS_BCPControlInfo_m.h
$O/src/CoreNode/OBS_ControlUnitInfo_m.o: src/CoreNode/OBS_ControlUnitInfo_m.cc \
	src/CoreNode/OBS_ControlUnitInfo_m.h
$O/src/CoreNode/OBS_CoreControlLogic.o: src/CoreNode/OBS_CoreControlLogic.cc \
	src/CoreNode/OBS_BCPControlInfo_m.h \
	src/CoreNode/OBS_ControlUnitInfo_m.h \
	src/CoreNode/OBS_CoreControlLogic.h \
	src/CoreNode/OBS_CoreInput.h \
	src/CoreNode/OBS_CoreOutput.h \
	src/CoreNode/OBS_CoreOutputHorizon.h \
	src/CoreNode/OBS_CoreRoutingTable.h \
	src/CoreNode/OBS_CoreRoutingTableEntry_m.h \
	src/CoreNode/OBS_OpticalCrossConnect.h \
	src/messages/OBS_BurstControlPacket_m.h
$O/src/CoreNode/OBS_CoreInput.o: src/CoreNode/OBS_CoreInput.cc \
	src/CoreNode/OBS_CoreInput.h
$O/src/CoreNode/OBS_CoreOutput.o: src/CoreNode/OBS_CoreOutput.cc \
	src/CoreNode/OBS_CoreOutput.h
$O/src/CoreNode/OBS_CoreOutputHorizon.o: src/CoreNode/OBS_CoreOutputHorizon.cc \
	src/CoreNode/OBS_CoreOutputHorizon.h
$O/src/CoreNode/OBS_CoreRoutingTable.o: src/CoreNode/OBS_CoreRoutingTable.cc \
	src/CoreNode/OBS_CoreRoutingTable.h \
	src/CoreNode/OBS_CoreRoutingTableEntry_m.h
$O/src/CoreNode/OBS_CoreRoutingTableEntry_m.o: src/CoreNode/OBS_CoreRoutingTableEntry_m.cc \
	src/CoreNode/OBS_CoreRoutingTableEntry_m.h
$O/src/CoreNode/OBS_EOConverter.o: src/CoreNode/OBS_EOConverter.cc \
	src/CoreNode/OBS_BCPControlInfo_m.h \
	src/messages/OBS_BurstControlPacket_m.h
$O/src/CoreNode/OBS_OEConverter.o: src/CoreNode/OBS_OEConverter.cc \
	src/CoreNode/OBS_BCPControlInfo_m.h \
	src/messages/OBS_BurstControlPacket_m.h
$O/src/CoreNode/OBS_OpticalCrossConnect.o: src/CoreNode/OBS_OpticalCrossConnect.cc \
	src/CoreNode/OBS_OpticalCrossConnect.h
$O/src/EdgeNode/BurstList.o: src/EdgeNode/BurstList.cc \
	src/EdgeNode/BurstList.h \
	src/EdgeNode/OBS_ScheduledBurstItem_m.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h
$O/src/EdgeNode/OBS_BurstDisassembler.o: src/EdgeNode/OBS_BurstDisassembler.cc \
	src/EdgeNode/OBS_BurstDisassembler.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h
$O/src/EdgeNode/OBS_BurstSender.o: src/EdgeNode/OBS_BurstSender.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	src/EdgeNode/BurstList.h \
	src/EdgeNode/OBS_BurstSender.h \
	src/EdgeNode/OBS_BurstSenderInfo_m.h \
	src/EdgeNode/OBS_BurstifierInfo_m.h \
	src/EdgeNode/OBS_ScheduledBurstItem_m.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/messages/OBS_Burst_m.h
$O/src/EdgeNode/OBS_BurstSenderInfo_m.o: src/EdgeNode/OBS_BurstSenderInfo_m.cc \
	src/EdgeNode/OBS_BurstSenderInfo_m.h
$O/src/EdgeNode/OBS_BurstifierInfo_m.o: src/EdgeNode/OBS_BurstifierInfo_m.cc \
	src/EdgeNode/OBS_BurstifierInfo_m.h
$O/src/EdgeNode/OBS_DispatcherRule.o: src/EdgeNode/OBS_DispatcherRule.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/EdgeNode/OBS_DispatcherRule.h
$O/src/EdgeNode/OBS_FileBurstifier.o: src/EdgeNode/OBS_FileBurstifier.cc \
	src/EdgeNode/OBS_BurstifierInfo_m.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h
$O/src/EdgeNode/OBS_PacketBurstifier.o: src/EdgeNode/OBS_PacketBurstifier.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	src/EdgeNode/OBS_BurstifierInfo_m.h \
	src/EdgeNode/OBS_PacketBurstifier.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h
$O/src/EdgeNode/OBS_PacketDispatcher.o: src/EdgeNode/OBS_PacketDispatcher.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/EdgeNode/OBS_DispatcherRule.h \
	src/EdgeNode/OBS_PacketDispatcher.h
$O/src/EdgeNode/OBS_ScheduledBurstItem_m.o: src/EdgeNode/OBS_ScheduledBurstItem_m.cc \
	src/EdgeNode/OBS_ScheduledBurstItem_m.h
$O/src/messages/OBS_Burst.o: src/messages/OBS_Burst.cc \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h
$O/src/messages/OBS_BurstControlPacket_m.o: src/messages/OBS_BurstControlPacket_m.cc \
	src/messages/OBS_BurstControlPacket_m.h
$O/src/messages/OBS_Burst_m.o: src/messages/OBS_Burst_m.cc \
	src/messages/OBS_Burst_m.h
$O/src/misc/OBS_DropBurst.o: src/misc/OBS_DropBurst.cc \
	src/messages/OBS_Burst.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/messages/OBS_Burst_m.h
$O/src/misc/OBS_OpticalMonitor.o: src/misc/OBS_OpticalMonitor.cc \
	src/messages/OBS_Burst.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/messages/OBS_Burst_m.h \
	src/misc/OBS_OpticalMonitor.h
$O/src/tests/PacketConverter.o: src/tests/PacketConverter.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h
$O/src/tests/sinks/testSink1.o: src/tests/sinks/testSink1.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/tests/sinks/testSink1.h
$O/src/tests/sinks/testSink2.o: src/tests/sinks/testSink2.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/EdgeNode/OBS_BurstifierInfo_m.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h \
	src/tests/sinks/testSink2.h
$O/src/tests/sinks/testSink3.o: src/tests/sinks/testSink3.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/CoreNode/OBS_BCPControlInfo_m.h \
	src/CoreNode/OBS_ControlUnitInfo_m.h \
	src/CoreNode/OBS_CoreControlLogic.h \
	src/CoreNode/OBS_CoreInput.h \
	src/CoreNode/OBS_CoreOutput.h \
	src/CoreNode/OBS_CoreOutputHorizon.h \
	src/CoreNode/OBS_CoreRoutingTable.h \
	src/CoreNode/OBS_CoreRoutingTableEntry_m.h \
	src/CoreNode/OBS_OpticalCrossConnect.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/messages/OBS_Burst_m.h \
	src/misc/OBS_OpticalMonitor.h \
	src/tests/sinks/testSink3.h
$O/src/tests/sinks/testSink4.o: src/tests/sinks/testSink4.cc \
	src/messages/OBS_BurstControlPacket_m.h \
	src/tests/sinks/testSink4.h
$O/src/tests/sinks/testSink5.o: src/tests/sinks/testSink5.cc \
	src/CoreNode/OBS_BCPControlInfo_m.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/tests/sinks/testSink5.h
$O/src/tests/sources/SourceControlInfo_m.o: src/tests/sources/SourceControlInfo_m.cc \
	src/tests/sources/SourceControlInfo_m.h
$O/src/tests/sources/testSource1.o: src/tests/sources/testSource1.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/tests/sources/testSource1.h
$O/src/tests/sources/testSource2.o: src/tests/sources/testSource2.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/EdgeNode/OBS_BurstifierInfo_m.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_Burst_m.h \
	src/tests/sources/SourceControlInfo_m.h \
	src/tests/sources/testSource2.h
$O/src/tests/sources/testSource3.o: src/tests/sources/testSource3.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	src/messages/OBS_Burst.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/messages/OBS_Burst_m.h \
	src/tests/sources/SourceControlInfo_m.h \
	src/tests/sources/testSource3.h
$O/src/tests/sources/testSource4.o: src/tests/sources/testSource4.cc \
	src/messages/OBS_BurstControlPacket_m.h \
	src/tests/sources/SourceControlInfo_m.h \
	src/tests/sources/testSource4.h
$O/src/tests/sources/testSource5.o: src/tests/sources/testSource5.cc \
	src/CoreNode/OBS_BCPControlInfo_m.h \
	src/messages/OBS_BurstControlPacket_m.h \
	src/tests/sources/testSource5.h

