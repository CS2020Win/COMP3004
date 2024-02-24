#ifndef ALLOCATIONSTRATEGY_H
#define ALLOCATIONSTRATEGY_H

class IAllocationStrategy {

public:
    virtual void makeDecision()=0;

};

#endif // ALLOCATIONSTRATEGY_H
