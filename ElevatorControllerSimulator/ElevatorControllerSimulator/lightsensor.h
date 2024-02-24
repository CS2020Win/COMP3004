#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <QObject>

class LightSensor : public QObject
{
    Q_OBJECT
public:
    explicit LightSensor(QObject *parent = nullptr);

    bool checkObstacle();

    void setObstacle(bool obstacle);

signals:
    void onObstacle();

private:
    bool obstacle;
};

#endif // LIGHTSENSOR_H
