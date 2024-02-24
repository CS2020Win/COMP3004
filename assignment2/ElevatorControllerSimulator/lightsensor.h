#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <QObject>

class LightSensor : public QObject
{
    Q_OBJECT
public:
    explicit LightSensor(QObject *parent = nullptr);

    bool checkObstacle();

signals:

};

#endif // LIGHTSENSOR_H
