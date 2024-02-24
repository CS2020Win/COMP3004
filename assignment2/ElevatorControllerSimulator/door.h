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
    explicit Door(QObject *parent = nullptr);

    void open();

    void close();

signals:


private:
    QTimer* m_timer;
    LightSensor *m_sensor;
    Bell* m_bell;

};

#endif // DOOR_H
