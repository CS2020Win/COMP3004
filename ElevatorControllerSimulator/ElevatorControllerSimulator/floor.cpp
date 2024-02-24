#include "floor.h"

Floor::Floor(int floorNumber, QObject *parent) : QObject(parent), floorNumber(floorNumber) {
    m_button_up = new FloorButton(this);
    m_button_down = new FloorButton(this);
}

void Floor::inform(Direction direction)
{
    
}

FloorButton* Floor::getButtonUp()
{
    return m_button_up;
}

FloorButton* Floor::getButtonDown()
{
    return m_button_down;
}

int Floor::getFloorNumber()
{
    return this->floorNumber;
}

void Floor::serviced(Direction direction)
{
    if(direction==Direction::UP) {
        this->m_button_up->switchOff();
    } else if(direction==Direction::DOWN) {
        this->m_button_down->switchOff();
    } else {
        this->m_button_up->switchOff();
        this->m_button_down->switchOff();
    }
    emit onUpdate();
}
