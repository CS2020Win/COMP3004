#ifndef FLOORSENSOR_H
#define FLOORSENSOR_H

#include <QObject>

class FloorSensor : public QObject {
    Q_OBJECT
public:
    explicit FloorSensor(QObject *parent = nullptr);

signals:
    void newFloor(int floorNumber);
};


#endif // FLOORSENSOR_H
