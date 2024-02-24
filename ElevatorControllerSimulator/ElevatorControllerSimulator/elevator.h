#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QList>
#include <QSet>

#include "display.h"
#include "button.h"
#include "destinationPanel.h"
#include "door.h"
#include "floorsensor.h"
#include "weightsensor.h"
#include "common.h"

class Elevator : public QObject
{
    Q_OBJECT
public:
    explicit Elevator(int elevatorNumber, QObject *parent = nullptr);

    void stop();
    void start(Direction direction);
    void overload(bool overload);

    Direction getCurrentDirection();
    int getCurrentFloor();

    QString toString();
    QString getMessage();

    int getFloorButtonState(int floorNumber);

    int getElevatorNumber();

    void setEmergency(QString message);

    Direction calcDirection();

    void openDoor();

    void closeDoor();

    void setObstacle(bool obstacle);

    bool isBusy();

    bool isDoorOpen();

    void addTargetFloor(int floorNumber);

signals:
    void onUpdate();
    void onFloorArrived(int floorNumber);
    void onFloorTextChanged(const QString &msg);
    void onDoorClosed();
    void onMessage(QString msg);

public slots:
    void newFloor(int floorNumber);
    void floorClick(int floorNumber);
    void setMessage(QString message);

private:
    Display* m_display;
    Button* m_button_open;
    Button* m_button_close;
    Button* m_button_help;
    DestinationPanel *m_destination_panel;
    Door *m_door;
    FloorSensor *m_floor_sensor;
    WeightSensor *m_weight_sensor;

    // current floor number
    int m_curr_floor;

    // current direction
    Direction m_curr_dirction;

    QList<int> m_target_list;

    int elevatorNumber;
    QString message;

    bool m_busy;
};

#endif // ELEVATOR_H
