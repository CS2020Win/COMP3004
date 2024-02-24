#ifndef OPPORTUNISTICSTRATEGY_H
#define OPPORTUNISTICSTRATEGY_H

#include "allocationstrategy.h"

class OpportunisticStrategy : public IAllocationStrategy {

public:
    void makeDecision() override;

};

#endif // OPPORTUNISTICSTRATEGY_H
