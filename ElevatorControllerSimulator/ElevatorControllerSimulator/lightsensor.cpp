#include "lightsensor.h"

LightSensor::LightSensor(QObject *parent)
    : QObject(parent), obstacle(false)
{

}

bool LightSensor::checkObstacle()
{
    return obstacle;
}

void LightSensor::setObstacle(bool obstacle)
{
    this->obstacle = obstacle;

}
