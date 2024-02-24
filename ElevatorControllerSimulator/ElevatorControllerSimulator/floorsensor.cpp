#include "floorsensor.h"

FloorSensor::FloorSensor(QObject *parent) : QObject(parent) {
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &FloorSensor::timeout);
}

void FloorSensor::start(int floorNumber, Direction direction)
{
    this->floorNumber = floorNumber;
    this->direction = direction;

    timer->start();
}

void FloorSensor::stop()
{
    timer->stop();
}

void FloorSensor::timeout()
{
    if(direction==Direction::UP) {
        floorNumber+=1;
        emit newFloor(floorNumber);
    } else if(direction==Direction::DOWN) {
        floorNumber-=1;
        emit newFloor(floorNumber);
    }
}

