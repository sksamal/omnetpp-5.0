//
// Generated file, do not edit! Created by nedtool 5.0 from Job.msg.
//

#ifndef __QUEUEING_JOB_M_H
#define __QUEUEING_JOB_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace queueing {

// cplusplus {{
#include "QueueingDefs.h"
// }}

/**
 * Class generated from <tt>Job.msg:21</tt> by nedtool.
 * <pre>
 * //
 * // Job message definition for queueing framework
 * //
 * message Job
 * {
 *     @customize(true);
 *     int priority;                // queueing priority
 *     simtime_t totalQueueingTime; // total time spent standing in queues
 *     simtime_t totalServiceTime;  // total time spent in servers
 *     simtime_t totalDelayTime;    // total time spent in delay modules
 *     int queueCount;              // the number of queue modules visited by the job
 *     int delayCount;              // the number of delay modules visited by the job
 *     int generation;              // how many times the original ancestor was copied
 * }
 * </pre>
 *
 * Job_Base is only useful if it gets subclassed, and Job is derived from it.
 * The minimum code to be written for Job is the following:
 *
 * <pre>
 * class Job : public Job_Base
 * {
 *   private:
 *     void copy(const Job& other) { ... }

 *   public:
 *     Job(const char *name=nullptr, int kind=0) : Job_Base(name,kind) {}
 *     Job(const Job& other) : Job_Base(other) {copy(other);}
 *     Job& operator=(const Job& other) {if (this==&other) return *this; Job_Base::operator=(other); copy(other); return *this;}
 *     virtual Job *dup() const {return new Job(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from Job_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(Job);
 * </pre>
 */
class Job_Base : public ::omnetpp::cMessage
{
  protected:
    int priority;
    ::omnetpp::simtime_t totalQueueingTime;
    ::omnetpp::simtime_t totalServiceTime;
    ::omnetpp::simtime_t totalDelayTime;
    int queueCount;
    int delayCount;
    int generation;

  private:
    void copy(const Job_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Job_Base&);
    // make constructors protected to avoid instantiation
    Job_Base(const char *name=nullptr, int kind=0);
    Job_Base(const Job_Base& other);
    // make assignment operator protected to force the user override it
    Job_Base& operator=(const Job_Base& other);

  public:
    virtual ~Job_Base();
    virtual Job_Base *dup() const {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class Job");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getPriority() const;
    virtual void setPriority(int priority);
    virtual ::omnetpp::simtime_t getTotalQueueingTime() const;
    virtual void setTotalQueueingTime(::omnetpp::simtime_t totalQueueingTime);
    virtual ::omnetpp::simtime_t getTotalServiceTime() const;
    virtual void setTotalServiceTime(::omnetpp::simtime_t totalServiceTime);
    virtual ::omnetpp::simtime_t getTotalDelayTime() const;
    virtual void setTotalDelayTime(::omnetpp::simtime_t totalDelayTime);
    virtual int getQueueCount() const;
    virtual void setQueueCount(int queueCount);
    virtual int getDelayCount() const;
    virtual void setDelayCount(int delayCount);
    virtual int getGeneration() const;
    virtual void setGeneration(int generation);
};

} // namespace queueing

#endif // ifndef __QUEUEING_JOB_M_H

