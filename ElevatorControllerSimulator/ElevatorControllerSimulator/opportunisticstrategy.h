#ifndef OPPORTUNISTICSTRATEGY_H
#define OPPORTUNISTICSTRATEGY_H

#include "allocationstrategy.h"

class OpportunisticStrategy : public IAllocationStrategy {

public:
    Elevator* makeDecision(int upFloor, int downFloor,
                           QList<Elevator*> elevators) override;

};

#endif // OPPORTUNISTICSTRATEGY_H
