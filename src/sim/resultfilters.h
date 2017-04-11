//==========================================================================
//  RESULTFILTERS.H - part of
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

#ifndef __OMNETPP_RESULTFILTERS_H
#define __OMNETPP_RESULTFILTERS_H

#include "common/expression.h"
#include "omnetpp/simkerneldefs.h"
#include "omnetpp/cresultfilter.h"
#include "omnetpp/csimulation.h"
#include "omnetpp/cstatistic.h"

namespace omnetpp {

using omnetpp::common::NaN;
using omnetpp::common::POSITIVE_INFINITY;
using omnetpp::common::NEGATIVE_INFINITY;

class SIM_API WarmupPeriodFilter : public cResultFilter
{
    private:
        simtime_t_cref getEndWarmupPeriod() {return getSimulation()->getWarmupPeriod();}
    public:
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, bool b, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, long l, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, unsigned long l, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, double d, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const SimTime& v, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const char *s, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, cObject *obj, cObject *details) override;
};

/**
 * @brief Result filter for counting signals. Signal values do not need to be numeric
 * to be counted.
 */
class SIM_API CountFilter : public cResultFilter
{
    protected:
        long count;
    public:
        CountFilter() {count = 0;}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, bool b, cObject *details) override {count++; fire(this,t,count,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, long l, cObject *details) override {count++; fire(this,t,count,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, unsigned long l, cObject *details) override {count++; fire(this,t,count,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, double d, cObject *details) override {count++; fire(this,t,count,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const SimTime& v, cObject *details) override {count++; fire(this,t,count,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const char *s, cObject *details) override {count++; fire(this,t,count,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, cObject *obj, cObject *details) override {count++; fire(this,t,count,details);}
};

/**
 * @brief Result filter that replaces every value with a constant. Signal values
 * do not need to be numeric.
 */
class SIM_API ConstantFilter : public cResultFilter
{
    protected:
        double c;
    public:
        ConstantFilter(double c) {this->c = c;}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, bool b, cObject *details) override {fire(this,t,c,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, long l, cObject *details) override {fire(this,t,c,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, unsigned long l, cObject *details) override {fire(this,t,c,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, double d, cObject *details) override {fire(this,t,c,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const SimTime& v, cObject *details) override {fire(this,t,c,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const char *s, cObject *details) override {fire(this,t,c,details);}
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, cObject *obj, cObject *details) override {fire(this,t,c,details);}
};

/**
 * @brief Result filter that replaces every value with zero.
 */
class SIM_API Constant0Filter : public ConstantFilter
{
    public:
        Constant0Filter() : ConstantFilter(0) {}
};

/**
 * @brief Result filter that replaces every value with 1.0.
 */
class SIM_API Constant1Filter : public ConstantFilter
{
    public:
        Constant1Filter() : ConstantFilter(1) {}
};

/**
 * @brief This class is a no-op filter.
 */
class SIM_API IdentityFilter : public cNumericResultFilter
{
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {return true;}
};

/**
 * @brief Filter that outputs the sum of signal values.
 */
class SIM_API SumFilter : public cNumericResultFilter
{
    protected:
        double sum;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {sum += value; value = sum; return true;}
    public:
        SumFilter() {sum = 0;}
};

/**
 * @brief Result filter that computes the mean of signal values
 */
class SIM_API MeanFilter : public cNumericResultFilter
{
    protected:
        long count;
        double sum;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {count++; sum += value; value = sum/count; return true;}
    public:
        MeanFilter() {count = 0; sum = 0;}
};

/**
 * @brief Result filter that computes the minimum of signal values
 */
class SIM_API MinFilter : public cNumericResultFilter
{
    protected:
        double min;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {if (value < min) min = value; value = min; return true;}
    public:
        MinFilter() {min = POSITIVE_INFINITY;}
};

/**
 * @brief Result filter that computes the maximum of signal values
 */
class SIM_API MaxFilter : public cNumericResultFilter
{
    protected:
        double max;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {if (value > max) max = value; value = max; return true;}
    public:
        MaxFilter() {max = NEGATIVE_INFINITY;}
};

/**
 * @brief Result filter that computes the time average of signal values
 */
class SIM_API TimeAverageFilter : public cNumericResultFilter
{
    protected:
        simtime_t startTime;
        simtime_t lastTime;
        double lastValue;
        double weightedSum;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override;
    public:
        TimeAverageFilter() {startTime = lastTime = -1; lastValue = weightedSum = 0;}
};

/**
 * @brief Result filter that removes repeated values
 */
class SIM_API RemoveRepeatsFilter : public cNumericResultFilter
{
    protected:
        double prev;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {bool repeated = (value==prev); prev = value; return !repeated;}
    public:
        RemoveRepeatsFilter() {prev = NaN;}
};

class SIM_API ExpressionFilter : public cNumericResultFilter
{
    public:
        typedef omnetpp::common::Expression Expression;
    protected:
        class ValueVariable : public Expression::Variable
        {
          private:
            ExpressionFilter *owner;
            double *currentValue;
          public:
            ValueVariable(ExpressionFilter *owner, double *currentValue) {this->owner = owner; this->currentValue = currentValue;}
            virtual Functor *dup() const override {return new ValueVariable(owner, currentValue);}
            virtual const char *getName() const override {return "<signalvalue>";}
            virtual char getReturnType() const override {return Expression::Value::DBL;}
            virtual Expression::Value evaluate(Expression::Value args[], int numargs) override {return *currentValue;}
        };
        //XXX currently unused
        class TimeVariable : public Expression::Variable
        {
          private:
            ExpressionFilter *owner;
          public:
            TimeVariable(ExpressionFilter *filter) {owner = filter;}
            virtual Functor *dup() const override {return new TimeVariable(owner);}
            virtual const char *getName() const override {return "<signaltime>";}
            virtual char getReturnType() const override {return Expression::Value::DBL;}
            virtual Expression::Value evaluate(Expression::Value args[], int numargs) override {return SIMTIME_DBL(owner->currentTime);}
        };

    protected:
        Expression expr;
        simtime_t currentTime;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override {currentTime = t; value = expr.doubleValue(); return true;}
    public:
        Expression& getExpression() {return expr;}
        virtual Expression::Functor *makeValueVariable(int index, cResultFilter *prevFilter) {throw cRuntimeError("constant expression cannot have variables");};
        Expression::Functor *makeTimeVariable() {return new TimeVariable(this);} // XXX: unused
};

/**
 * @brief Result filter that computes an expression from signal values
 */
class SIM_API UnaryExpressionFilter : public ExpressionFilter
{
    protected:
        double currentValue;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override;
    public:
        UnaryExpressionFilter() {}
        virtual std::string str() const override {return expr.str()+" (UnaryExpressionFilter)";}
        virtual Expression::Functor *makeValueVariable(int index, cResultFilter *prevFilter) override {ASSERT(index == 0); return new ValueVariable(this, &currentValue);}
};

/**
 * @brief Result filter that computes an expression from multiple signal values.
 */
class SIM_API NaryExpressionFilter : public ExpressionFilter
{
    protected:
        int signalCount;
        cResultFilter **prevFilters;
        double *currentValues;
    protected:
        using ExpressionFilter::process;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, bool b, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, long l, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, unsigned long l, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, double d, cObject *details) override;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, const SimTime& v, cObject *details) override;
        virtual bool process(cResultFilter *prev, simtime_t& t, double& value);
        virtual void subscribedTo(cResultFilter *prev) override {}
    public:
        NaryExpressionFilter(int signalCount) {this->signalCount = signalCount; prevFilters = new cResultFilter*[signalCount]; currentValues = new double[signalCount];}
        virtual ~NaryExpressionFilter() {delete [] prevFilters; delete [] currentValues; }
        virtual std::string str() const override {return expr.str()+" (NaryExpressionFilter)";}
        virtual Expression::Functor *makeValueVariable(int index, cResultFilter *prevFilter) override;
};

/**
 * @brief Filter that expects a cPacket and outputs its length in bytes (getByteLength()).
 */
class SIM_API PacketBytesFilter : public cObjectResultFilter
{
    public:
        using cObjectResultFilter::receiveSignal;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, cObject *object, cObject *details) override;
};

/**
 * @brief Filter that expects a cPacket and outputs its length in bits (getBitLength()).
 */
class SIM_API PacketBitsFilter : public cObjectResultFilter
{
    public:
        using cObjectResultFilter::receiveSignal;
        virtual void receiveSignal(cResultFilter *prev, simtime_t_cref t, cObject *object, cObject *details) override;
};

/**
 * @brief Filter that outputs the sum of signal values divided by the measurement
 * interval (simtime minus warmupPeriod)
 */
class SIM_API SumPerDurationFilter : public cNumericResultFilter
{
    protected:
        double sum;
    protected:
        virtual bool process(simtime_t& t, double& value, cObject *details) override;
    public:
        SumPerDurationFilter() {sum = 0;}
};

}  // namespace omnetpp

#endif


