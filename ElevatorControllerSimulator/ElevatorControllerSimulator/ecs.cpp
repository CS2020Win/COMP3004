#include "ecs.h"
#include "opportunisticstrategy.h"

ECS::ECS(QObject *parent) : QObject(parent), emergency(false) {

    this->name = "Elevator Control System";

    for(int i=0;i<Common::elevatorCount;i++) {
        Elevator* elevator = new Elevator(i, this);
        m_elevator_list.append(elevator);
        connect(elevator, &Elevator::onDoorClosed, this, &ECS::readyToMove);
        connect(elevator, &Elevator::onFloorArrived, this, &ECS::onElevatorArrived);
        connect(elevator, &Elevator::onMessage, this, &ECS::onMessage);
    }

    for(int i=0;i<Common::floorCount;i++) {
        Floor *floor = new Floor(i, this);
        m_floor_list.append(floor);
    }

    m_current_strategy = new OpportunisticStrategy();
}

void ECS::floorRequest(int floorNumber, Direction direction)
{
    QString dir = "";
    if(direction==Direction::UP) {
        dir = "Up";
    } else if(direction==Direction::DOWN) {
        dir = "Down";
    }
    emit onMessage(QString("%1 receive %2 request from Floor %3").arg(name)
                   .arg(dir).arg(floorNumber+1));
    if(emergency) return;

    Floor *floor = m_floor_list.at(floorNumber);

    Elevator* target = nullptr;
    if(direction==Direction::UP && floor->getButtonUp()->getState()==0) {
        floor->getButtonUp()->switchOn();
        target = m_current_strategy->makeDecision(floorNumber, -1, m_elevator_list);
    } else if(direction == Direction::DOWN && floor->getButtonDown()->getState()==0) {
        floor->getButtonDown()->switchOn();
        target = m_current_strategy->makeDecision(-1, floorNumber, m_elevator_list);
    }

    if(target != nullptr) {
        target->addTargetFloor(floorNumber);
        processRequest(target);
    }

}

void ECS::carRequest(int elevatorNumber, int floorNumber)
{
    Elevator *elevator = m_elevator_list.at(elevatorNumber);
    elevator->floorClick(floorNumber);

    if(emergency) return;

    processRequest(elevator);
}

void ECS::readyToMove()
{
    Elevator* elevator = qobject_cast<Elevator*>(sender());
    processRequest(elevator);
}

void ECS::onElevatorArrived(int floorNumber)
{
    Elevator* elevator = qobject_cast<Elevator*>(sender());

    emit onMessage(QString("Elevator %1 arrived Floor %2").arg(elevator->getElevatorNumber()+1).arg(floorNumber+1));

    Floor* floor = m_floor_list.at(floorNumber);
    floor->serviced(elevator->getCurrentDirection());

    elevator->openDoor();
}

void ECS::onFireAlarm()
{
    emit onMessage(QString("%1 receive Fire Alarm").arg(name));
    emergency = true;
    emergency_message = "Fire Occur, Please leave the elevator";
    for(int i=0;i<m_elevator_list.size();i++) {
        Elevator *elevator = m_elevator_list.at(i);
        processRequest(elevator);
    }
}

void ECS::onFireAlarm(int elevatorNumber)
{
    emit onMessage(QString("%1 receive Fire Alarm").arg(name));
    emergency = true;
    emergency_message = "Fire Occur, Please leave the elevator";
    for(int i=0;i<m_elevator_list.size();i++) {
        Elevator *elevator = m_elevator_list.at(i);
        processRequest(elevator);
    }
}

void ECS::onOverload(int elevatorNumber)
{
    emit onMessage(QString("%1 receive Overload Signal").arg(name));
}

void ECS::onPowerOut()
{
    emit onMessage(QString("%1 receive PowerOut Signal").arg(name));
    emergency = true;
    emergency_message = "Power Out, Please leave the elevator";
    for(int i=0;i<m_elevator_list.size();i++) {
        Elevator *elevator = m_elevator_list.at(i);
        processRequest(elevator);
    }
}

Elevator *ECS::getElevator(int elevatorNumber)
{
    return m_elevator_list.at(elevatorNumber);
}

Floor *ECS::getFloor(int floorNumber)
{
    return m_floor_list.at(floorNumber);
}

void ECS::processRequest(Elevator* elevator)
{
    if(emergency) {
        elevator->setEmergency(emergency_message);
    } else {
        if(!elevator->isBusy() && !elevator->isDoorOpen()) {
            Direction direction = elevator->calcDirection();
            elevator->start(direction);
        }
    }
}
