#ifndef ALLOCATIONSTRATEGY_H
#define ALLOCATIONSTRATEGY_H

#include <QList>

#include "elevator.h"

class IAllocationStrategy {

public:
    virtual Elevator* makeDecision(int upFloor,
                                   int downFloor,
                                   QList<Elevator*> elevators)=0;

};

#endif // ALLOCATIONSTRATEGY_H
