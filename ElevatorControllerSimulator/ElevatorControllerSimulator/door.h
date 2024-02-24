#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "bell.h"
#include "lightsensor.h"

class Door : public QObject
{
    Q_OBJECT
public:
    explicit Door(int elevatorNumber, QObject *parent = nullptr);

    void open();

    void close();

    bool isOpen();

    bool isObstacle();

    void setObstacle(bool obstacle);

    void setOverload(bool overload);
signals:
    void onDoorClosed();
    void onMessage(QString message);
    void onAlarm(QString message);

private:
    QTimer* m_timer;
    LightSensor *m_sensor;
    Bell* m_bell;

    int m_count;
    bool m_state;
    bool m_overload;
    int elevatorNumber;
};

#endif // DOOR_H
