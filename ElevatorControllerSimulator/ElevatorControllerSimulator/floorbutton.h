#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

#include "button.h"

class FloorButton : public Button {
    Q_OBJECT
public:
    explicit FloorButton(QObject *parent = nullptr);

    void switchOn();

    void switchOff();

    int getState();

private:
    int m_state;
};

#endif // FLOORBUTTON_H
