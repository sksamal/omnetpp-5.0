#
# OMNeT++/OMNEST Makefile for FatTree-New
#
# This file was generated with the command:
#  opp_makemake -f --deep -I../../inet/src -I../../inet/src/inet/networklayer/contract/ipv4 -I../../inet/src/inet/networklayer/common -I../../inet/src/inet/networklayer/contract -I../../inet/src/inet/transportlayer/contract/tcp -I../../inet/src/inet/applications/tcpapp -I../../inet/src/inet/networklayer/ipv4 -L../../inet/out/$$\(CONFIGNAME\)/src -lINET -KINET_PROJ=../../inet
#

# Name of target to be created (-o option)
TARGET = FatTree-New$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inet/src \
    -I../../inet/src/inet/networklayer/contract/ipv4 \
    -I../../inet/src/inet/networklayer/common \
    -I../../inet/src/inet/networklayer/contract \
    -I../../inet/src/inet/transportlayer/contract/tcp \
    -I../../inet/src/inet/applications/tcpapp \
    -I../../inet/src/inet/networklayer/ipv4 \
    -I. \
    -Icomponents \
    -Ilogic \
    -Ilogic/ipaddress \
    -Ilogic/routing \
    -Imessages \
    -Iutil

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inet/out/$(CONFIGNAME)/src  -lINET
LIBS += -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/components/TSink.o \
    $O/components/TRouter.o \
    $O/components/TGenerator.o \
    $O/logic/ipaddress/CoreIPConfig.o \
    $O/logic/ipaddress/ContIPConfig.o \
    $O/logic/ipaddress/RackIPConfig.o \
    $O/logic/ipaddress/AggIPConfig.o \
    $O/logic/ipaddress/ServerIPConfig.o \
    $O/logic/routing/ConfigRouting.o \
    $O/util/ServerMap.o \
    $O/util/SocketMapExt.o \
    $O/util/TCPVMSet.o \
    $O/util/ServiceMap.o \
    $O/util/ServerStateMap.o \
    $O/util/ClientTimeMap.o \
    $O/util/TCPHVSet.o \
    $O/components/TPacket_m.o \
    $O/messages/StartHV_m.o \
    $O/messages/StartClient_m.o \
    $O/messages/RequestMsg_m.o \
    $O/messages/ShutDownHV_m.o \
    $O/messages/TTimer_m.o \
    $O/messages/StartVM_m.o \
    $O/messages/StopClient_m.o \
    $O/messages/ShutDownVM_m.o \
    $O/messages/TTimerCon_m.o \
    $O/messages/ReplyMsg_m.o \
    $O/messages/VMMigMsg_m.o

# Message files
MSGFILES = \
    components/TPacket.msg \
    messages/StartHV.msg \
    messages/StartClient.msg \
    messages/RequestMsg.msg \
    messages/ShutDownHV.msg \
    messages/TTimer.msg \
    messages/StartVM.msg \
    messages/StopClient.msg \
    messages/ShutDownVM.msg \
    messages/TTimerCon.msg \
    messages/ReplyMsg.msg \
    messages/VMMigMsg.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet

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
	$(Q)-rm -f FatTree-New FatTree-New.exe libFatTree-New.so libFatTree-New.a libFatTree-New.dll libFatTree-New.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h ./*_sm.cc ./*_sm.h
	$(Q)-rm -f components/*_m.cc components/*_m.h components/*_sm.cc components/*_sm.h
	$(Q)-rm -f logic/*_m.cc logic/*_m.h logic/*_sm.cc logic/*_sm.h
	$(Q)-rm -f logic/ipaddress/*_m.cc logic/ipaddress/*_m.h logic/ipaddress/*_sm.cc logic/ipaddress/*_sm.h
	$(Q)-rm -f logic/routing/*_m.cc logic/routing/*_m.h logic/routing/*_sm.cc logic/routing/*_sm.h
	$(Q)-rm -f messages/*_m.cc messages/*_m.h messages/*_sm.cc messages/*_sm.h
	$(Q)-rm -f util/*_m.cc util/*_m.h util/*_sm.cc util/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc components/*.cc logic/*.cc logic/ipaddress/*.cc logic/routing/*.cc messages/*.cc util/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/components/TGenerator.o: components/TGenerator.cc \
	components/TGenerator.h \
	components/TPacket_m.h
$O/components/TPacket_m.o: components/TPacket_m.cc \
	components/TPacket_m.h
$O/components/TRouter.o: components/TRouter.cc \
	components/TPacket_m.h \
	components/TRouter.h
$O/components/TSink.o: components/TSink.cc \
	components/TPacket_m.h \
	components/TSink.h
$O/logic/ipaddress/AggIPConfig.o: logic/ipaddress/AggIPConfig.cc \
	logic/ipaddress/AggIPConfig.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h
$O/logic/ipaddress/ContIPConfig.o: logic/ipaddress/ContIPConfig.cc \
	logic/ipaddress/ContIPConfig.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h
$O/logic/ipaddress/CoreIPConfig.o: logic/ipaddress/CoreIPConfig.cc \
	logic/ipaddress/CoreIPConfig.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h
$O/logic/ipaddress/RackIPConfig.o: logic/ipaddress/RackIPConfig.cc \
	logic/ipaddress/RackIPConfig.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h
$O/logic/ipaddress/ServerIPConfig.o: logic/ipaddress/ServerIPConfig.cc \
	logic/ipaddress/ServerIPConfig.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h
$O/logic/routing/ConfigRouting.o: logic/routing/ConfigRouting.cc \
	logic/routing/ConfigRouting.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h
$O/messages/ReplyMsg_m.o: messages/ReplyMsg_m.cc \
	messages/ReplyMsg_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/RequestMsg_m.o: messages/RequestMsg_m.cc \
	messages/RequestMsg_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/ShutDownHV_m.o: messages/ShutDownHV_m.cc \
	messages/ShutDownHV_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/ShutDownVM_m.o: messages/ShutDownVM_m.cc \
	messages/ShutDownVM_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/StartClient_m.o: messages/StartClient_m.cc \
	messages/StartClient_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/StartHV_m.o: messages/StartHV_m.cc \
	messages/StartHV_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/StartVM_m.o: messages/StartVM_m.cc \
	messages/StartVM_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/StopClient_m.o: messages/StopClient_m.cc \
	messages/StopClient_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/TTimerCon_m.o: messages/TTimerCon_m.cc \
	messages/TTimerCon_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/TTimer_m.o: messages/TTimer_m.cc \
	messages/TTimer_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/messages/VMMigMsg_m.o: messages/VMMigMsg_m.cc \
	messages/VMMigMsg_m.h \
	$(INET_PROJ)/src/inet/applications/tcpapp/GenericAppMsg_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h
$O/util/ClientTimeMap.o: util/ClientTimeMap.cc \
	util/ClientTimeMap.h
$O/util/ServerMap.o: util/ServerMap.cc \
	util/ServerMap.h \
	util/TCPVMSet.h
$O/util/ServerStateMap.o: util/ServerStateMap.cc \
	util/ServerStateMap.h
$O/util/ServiceMap.o: util/ServiceMap.cc \
	util/ServiceMap.h
$O/util/SocketMapExt.o: util/SocketMapExt.cc \
	util/SocketMapExt.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/tcp/TCPSocketMap.h
$O/util/TCPHVSet.o: util/TCPHVSet.cc \
	util/TCPHVSet.h
$O/util/TCPVMSet.o: util/TCPVMSet.cc \
	util/TCPVMSet.h

