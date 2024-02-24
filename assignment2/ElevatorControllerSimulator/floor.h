#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>

#include "floorbutton.h"
#include "ecs.h"
#include "common.h"

class Floor : public QObject
{
    Q_OBJECT
public:
    explicit Floor(QObject *parent = nullptr);

    void inform(Direction direction);

public slots:
    void serviced(Direction direction);

private:
    ECS *m_ecs;
    FloorButton* m_button_up;
    FloorButton* m_button_down;

    // current floor number
    int floorNumber;
};

#endif // FLOOR_H
