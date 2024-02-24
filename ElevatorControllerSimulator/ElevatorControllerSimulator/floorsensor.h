#ifndef FLOORSENSOR_H
#define FLOORSENSOR_H

#include <QObject>
#include <QTimer>

#include "common.h"

class FloorSensor : public QObject {
    Q_OBJECT
public:
    explicit FloorSensor(QObject *parent = nullptr);

    void start(int floorNumber, Direction direction);

    void stop();

signals:
    void newFloor(int floorNumber);

private:

    void timeout();

    QTimer *timer;

    int floorNumber;
    Direction direction;
};


#endif // FLOORSENSOR_H
