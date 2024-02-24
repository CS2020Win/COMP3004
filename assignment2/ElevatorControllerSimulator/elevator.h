#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QList>

#include "display.h"
#include "button.h"
#include "destinationbutton.h"
#include "door.h"
#include "floorsensor.h"
#include "weightsensor.h"
#include "common.h"

class Elevator : public QObject
{
    Q_OBJECT
public:
    explicit Elevator(QObject *parent = nullptr);

    void stop();
    void start(Direction direction);
    void overload();

public slots:
    void newFloor(int floorNumber);

private:
    Display* m_display;
    Button* m_button_open;
    Button* m_button_close;
    Button* m_button_help;
    QList<DestinationButton*> m_destination_button_list;
    Door *m_door;
    FloorSensor *m_floor_sensor;
    WeightSensor *m_weight_sensor;

    // current floor number
    int m_current_floor;

    // current direction
    Direction *m_curr_dirction;
};

#endif // ELEVATOR_H
