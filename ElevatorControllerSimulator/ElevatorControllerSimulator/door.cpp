#include "door.h"

Door::Door(int elevatorNumber, QObject *parent) : QObject(parent),
    m_state(0), m_count(0), m_overload(false),elevatorNumber(elevatorNumber) {

    m_sensor = new LightSensor(this);

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Door::close);

}

void Door::open()
{
    if(m_state==0) {
        m_state = 1;
        m_timer->start(1000*5);
        emit onMessage(QString("Elevator %1 Door Open").arg(elevatorNumber+1));
    }
}

void Door::close()
{
    if(m_state==1) {
        if(m_sensor->checkObstacle()) {
            m_count++;
            emit onMessage(QString("Elevator %1 Door Obstacle %2 times").arg(elevatorNumber+1).arg(m_count));
            if(m_count>=3) {
                emit onAlarm(QString("Door Obstacle"));
            }
        } else if(m_overload) {
            emit onMessage(QString("Elevator %1 Door close failed, Overload").arg(elevatorNumber+1));
        } else {
            m_timer->stop();
            m_state = 0;
            emit onDoorClosed();
            emit onMessage(QString("Elevator %1 Door Closed").arg(elevatorNumber+1));
            if(m_count>=3) {
                emit onAlarm("");
                m_count = 0;
            }
        }
    }
}

bool Door::isOpen()
{
    return m_state ==1;
}

bool Door::isObstacle()
{
    return m_sensor->checkObstacle();
}

void Door::setObstacle(bool obstacle)
{
    m_sensor->setObstacle(obstacle);
}

void Door::setOverload(bool overload)
{
    this->m_overload = overload;
    if(m_overload) {
        emit onAlarm(QString("Overload"));
    } else {
        emit onAlarm(QString(""));
    }
}
