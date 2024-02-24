#include "elevator.h"

Elevator::Elevator(int elevatorNumber, QObject *parent) : QObject(parent), m_busy(false),
    elevatorNumber(elevatorNumber),
    m_curr_floor(0),
    m_curr_dirction(Direction::IDEL) {
    m_floor_sensor = new FloorSensor(this);

    m_destination_panel = new DestinationPanel(this);
    connect(m_floor_sensor, &FloorSensor::newFloor, m_destination_panel, &DestinationPanel::newFloor);

    connect(m_floor_sensor, &FloorSensor::newFloor, this, &Elevator::newFloor);


    m_door = new Door(elevatorNumber,this);
    connect(m_door, &Door::onDoorClosed, this, &Elevator::onDoorClosed);
    connect(m_door, &Door::onMessage, this, &Elevator::onMessage);
    connect(m_door, &Door::onAlarm, this, &Elevator::setMessage);
}

void Elevator::stop()
{

}

void Elevator::start(Direction direction)
{
    m_curr_dirction = direction;
    if(direction!=Direction::IDEL) {
        emit onMessage(QString("Elevator %1 start move").arg(elevatorNumber+1));
        m_floor_sensor->start(m_curr_floor, m_curr_dirction);
        m_busy = true;
    } else if(!m_target_list.empty()) {
        newFloor(m_curr_floor);
    }
    emit onUpdate();
    emit onFloorTextChanged(toString());
}

void Elevator::overload(bool overload)
{
    m_door->setOverload(overload);
}

Direction Elevator::getCurrentDirection()
{
    return m_curr_dirction;
}

int Elevator::getCurrentFloor()
{
    return m_curr_floor;
}

QString Elevator::toString()
{
    QString dir = "";
    if(m_curr_dirction == Direction::UP) {
        dir = "⇧";
    } else if(m_curr_dirction == Direction::DOWN) {
        dir = "⇩";
    } else {
        dir = "";
    }
    return QString("%1 %2").arg(dir).arg(m_curr_floor+1);
}

QString Elevator::getMessage()
{
    return this->message;
}

int Elevator::getFloorButtonState(int floorNumber)
{
    return m_destination_panel->getButton(floorNumber)->getState();
}

int Elevator::getElevatorNumber()
{
    return elevatorNumber;
}

void Elevator::setEmergency(QString message)
{
    this->message = message;
    emit onUpdate();
    if(!m_target_list.contains(0)) {
        m_target_list.append(0);
    }

    if(!m_busy && !m_door->isOpen()) {
        start(calcDirection());
    }
}

Direction Elevator::calcDirection()
{
    int upCount=0, downCount=0;

    QSet<int> targetSet;

    for(int i=0;i<m_target_list.size();i++) {
        targetSet.insert(m_target_list.at(i));
    }

    QSetIterator<int> iterator(targetSet);

    while(iterator.hasNext()) {
        int target = iterator.next();
        if(m_curr_floor>target) {
            downCount++;
        } else if(m_curr_floor==target) {

        } else {
            upCount++;
        }
    }
    Direction direction = m_curr_dirction;
    if((direction==Direction::UP && upCount==0)||(direction==Direction::DOWN &&downCount==0)) {
       direction=Direction::IDEL;
    }
    if(direction==Direction::IDEL) {
        if(upCount!=0||downCount!=0) {
            if(upCount>downCount) {
                direction = Direction::UP;
            } else {
                direction = Direction::DOWN;
            }
        }
    }
    return direction;
}

void Elevator::openDoor()
{
    if(!m_busy) {
        m_door->open();
    }
}

void Elevator::closeDoor()
{
    if(!m_busy) {
        m_door->close();
    }
}

void Elevator::setObstacle(bool obstacle)
{
    m_door->setObstacle(obstacle);
}

bool Elevator::isBusy()
{
    return m_busy;
}

bool Elevator::isDoorOpen()
{
    return m_door->isOpen();
}

void Elevator::addTargetFloor(int floorNumber)
{
    if(!m_target_list.contains(floorNumber)) {
        m_target_list.append(floorNumber);
    }
}

void Elevator::newFloor(int floorNumber)
{
    m_curr_floor = floorNumber;
    if(m_target_list.contains(floorNumber)) {
        m_floor_sensor->stop();
        m_target_list.removeOne(floorNumber);
        m_curr_dirction = calcDirection();
        m_busy = false;
        emit onFloorArrived(floorNumber);
    }
    emit onFloorTextChanged(toString());
    emit onUpdate();
}

void Elevator::floorClick(int floorNumber)
{
    m_destination_panel->floorClick(floorNumber);
    if(!m_target_list.contains(floorNumber)) {
        m_target_list.append(floorNumber);
    }
}

void Elevator::setMessage(QString message)
{
    this->message = message;
    emit onUpdate();
}


