#include "destinationbutton.h"

DestinationButton::DestinationButton(int floorNumber, QObject *parent) : Button(parent),
    floorNumber(floorNumber),
    m_state(0) {

}

void DestinationButton::onClick()
{
    m_state = 1;
    emit onClicked(floorNumber);
}

int DestinationButton::getState()
{
    return m_state;
}

void DestinationButton::setState(int state)
{
    m_state = state;
}
