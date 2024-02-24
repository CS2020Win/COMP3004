#ifndef ECS_H
#define ECS_H

#include <QObject>
#include <QList>
#include "common.h"
#include "elevator.h"
#include "allocationstrategy.h"

class ECS : public QObject
{
    Q_OBJECT
public:
    explicit ECS(QObject *parent = nullptr);

    void floorRequest(int floorNumber, Direction direction);

    void carRequest(int elevatorNumber, int floorNumber);

    void readyToMove(int elevatorNumber);

    void onElevatorArrived(int elevatorNumber, int floorNumber);

    void onFireAlarm();

    void onFireAlarm(int elevatorNumber);

    void onOverload(int elevatorNumber);

    void onPowerOut();

signals:
    void floorServiced(Direction direction);

private:
    QList<Elevator*> m_elevator_list;
    // current allocation strategy
    IAllocationStrategy *m_current_strategy;
};

#endif // ECS_H
