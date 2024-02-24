#ifndef WEIGHTSENSOR_H
#define WEIGHTSENSOR_H

#include <QObject>

class WeightSensor : public QObject
{
    Q_OBJECT
public:
    explicit WeightSensor(QObject *parent = nullptr);

    bool checkWeight();

private:
    int m_max_weight;
};

#endif // WEIGHTSENSOR_H
