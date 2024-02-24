#include "opportunisticstrategy.h"
#include "common.h"

Elevator* OpportunisticStrategy::makeDecision(int upFloor, int downFloor,
                                              QList<Elevator*> elevatorList)
{
    if(upFloor>=0) {
        Elevator *target = nullptr;
        int min = Common::floorCount*2+1;
        for(int i=0;i<elevatorList.size();i++) {
            Elevator *curr = elevatorList.at(i);
            int dis = min+1;
            if(curr->getCurrentDirection()==Direction::UP || curr->getCurrentDirection()==Direction::IDEL) {
                if(curr->getCurrentFloor()<=upFloor) {
                    dis = qAbs(curr->getCurrentFloor() - upFloor);
                } else {
                    dis = qAbs(Common::floorCount *2 - upFloor - curr->getCurrentFloor());
                }
            } else {
                dis =  qAbs(Common::floorCount *2 - upFloor - curr->getCurrentFloor());
            }
            if(dis<min) {
                min = dis;
                target = curr;
            }
        }
        return target;
    }

    if(downFloor>=0) {
        Elevator *target = nullptr;
        int min = Common::floorCount*2+1;
        for(int j=0;j<elevatorList.size();j++) {
            Elevator *curr = elevatorList.at(j);
            int dis = min+1;
            if(curr->getCurrentDirection()==Direction::DOWN  || curr->getCurrentDirection()==Direction::IDEL) {
                if(curr->getCurrentFloor()<=downFloor) {
                    dis = qAbs(curr->getCurrentFloor() - downFloor);
                } else {
                    dis = qAbs(Common::floorCount *2 - downFloor- curr->getCurrentFloor());
                }
            } else {
                dis =  qAbs(Common::floorCount *2 - downFloor - curr->getCurrentFloor());
            }
            if(dis<min) {
                min = dis;
                target = curr;
            }
        }
        return target;
    }

}
