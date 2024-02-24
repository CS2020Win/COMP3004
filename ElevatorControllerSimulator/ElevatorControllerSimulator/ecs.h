#ifndef ECS_H
#define ECS_H

#include <QObject>
#include <QList>

#include "common.h"
#include "elevator.h"
#include "floor.h"
#include "allocationstrategy.h"
#include "common.h"

class ECS : public QObject
{
    Q_OBJECT
public:
    explicit ECS(QObject *parent = nullptr);

    void floorRequest(int floorNumber, Direction direction);

    void carRequest(int elevatorNumber, int floorNumber);

    void readyToMove();

    void onElevatorArrived(int floorNumber);

    void onFireAlarm();

    void onFireAlarm(int elevatorNumber);

    void onOverload(int elevatorNumber);

    void onPowerOut();

    Elevator* getElevator(int elevatorNumber);

    Floor* getFloor(int floorNumber);

signals:
    void floorServiced(Direction direction);

    void onMessage(QString message);

protected:
    void processRequest(Elevator *elevator);

private:
    QList<Elevator*> m_elevator_list;

    QList<Floor*> m_floor_list;
    // current allocation strategy
    IAllocationStrategy *m_current_strategy;

    QList<int> m_up_requests;
    QList<int> m_down_requests;

    bool emergency;
    QString emergency_message;

    QString name;
};

#endif // ECS_H
