//==========================================================================
//  LOGBUFFER.H - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __OMNETPP_QTENV_LOGBUFFER_H
#define __OMNETPP_QTENV_LOGBUFFER_H

#include <vector>
#include "omnetpp/simtime_t.h"
#include "qtutil.h"
#include "circularbuffer.h"

namespace omnetpp {

class cModule;

namespace qtenv {

/**
 * Stores textual debug output from modules.
 */
class QTENV_API LogBuffer : public QObject
{
    Q_OBJECT // for signals

  public:
    struct Line {
        int contextComponentId;
        const char *prefix;
        const char *line;  // including newline
        Line(int contextComponentId, const char *prefix, const char *line) :
            contextComponentId(contextComponentId), prefix(prefix), line(line) {}
    };
    struct MessageSend {
        cMessage *msg;
        std::vector<int> hopModuleIds; //TODO also: txStartTime, propagationDelay, duration for each hop
    };
    struct Entry {
        eventnumber_t eventNumber = 0; // 0 for initialization, >0 afterwards
        simtime_t simtime = 0;
        int componentId = 0;  // 0 for info log lines
        //TODO msg name, class, kind, previousEventNumber
        const char *banner = nullptr;
        std::vector<Line> lines;
        std::vector<MessageSend> msgs;

        bool isEvent();
        ~Entry();
    };

  protected:
    circular_buffer<Entry*> entries;
    int maxNumEntries;
    int entriesDiscarded;

  protected:
    void discardEventsIfLimitExceeded();
    void fillEntry(Entry *entry, eventnumber_t e, simtime_t t, cModule *mod, const char *banner);

  public:
    LogBuffer();
    ~LogBuffer();

    void addInitialize(cComponent *component, const char *banner);
    void addEvent(eventnumber_t e, simtime_t t, cModule *moduleIds, const char *banner);
    void addLogLine(const char *prefix, const char *text);
    void addLogLine(const char *prefix, const char *text, int len);
    void addInfo(const char *text);
    void addInfo(const char *text, int len);

    void beginSend(cMessage *msg);
    void messageSendDirect(cMessage *msg, cGate *toGate, simtime_t propagationDelay, simtime_t transmissionDelay);
    void messageSendHop(cMessage *msg, cGate *srcGate);
    void messageSendHop(cMessage *msg, cGate *srcGate, simtime_t propagationDelay, simtime_t transmissionDelay);
    void endSend(cMessage *msg);

    void setMaxNumEntries(int limit); // when exceeded, oldest entries are discarded
    int getMaxNumEntries()  {return maxNumEntries;}

    const circular_buffer<Entry*>& getEntries() const {return entries;}
    int getNumEntries() const {return entries.size();}
    int getNumEntriesDiscarded() const {return entriesDiscarded;}
    int findEntryByEventNumber(eventnumber_t eventNumber);
    Entry *getEntryByEventNumber(eventnumber_t eventNumber);

    void clear();

    void dump() const;

signals:
    void logEntryAdded();
    void logLineAdded();
    void messageSendAdded();

    // When this signal is fired, the entry in the parameter is
    // no longer in the buffer, but is not deleted yet.
    void entryDiscarded(LogBuffer::Entry *discardedEntry);
};

} // namespace qtenv
} // namespace omnetpp


#endif


