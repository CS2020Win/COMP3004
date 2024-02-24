#include "floorbutton.h"

FloorButton::FloorButton(QObject *parent) : Button(parent), m_state(0) {

}

void FloorButton::switchOn()
{
    m_state=1;
}

void FloorButton::switchOff()
{
    m_state=0;
}

int FloorButton::getState()
{
    return m_state;
}
