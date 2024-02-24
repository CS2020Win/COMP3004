#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>

#include "floorbutton.h"
#include "common.h"

class Floor : public QObject
{
    Q_OBJECT
public:
    explicit Floor(int floorNumber, QObject *parent = nullptr);

    void inform(Direction direction);

    FloorButton* getButtonUp();

    FloorButton* getButtonDown();

    int getFloorNumber();

signals:
    void onUpdate();

public slots:
    void serviced(Direction direction);

private:
    FloorButton* m_button_up;
    FloorButton* m_button_down;

    // current floor number
    int floorNumber;
};

#endif // FLOOR_H
