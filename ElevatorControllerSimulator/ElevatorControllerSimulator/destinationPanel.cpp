#include "destinationpanel.h"
#include "common.h"


DestinationPanel::DestinationPanel(QObject *parent) : QObject(parent) {

    for(int i=0;i<Common::floorCount;i++) {
        DestinationButton* btn = new DestinationButton(i+1);
        m_destination_button_list.append(btn);
    }

}

DestinationButton *DestinationPanel::getButton(int floorNumber)
{
    return m_destination_button_list.at(floorNumber);
}

void DestinationPanel::newFloor(int floorNumber) {
    DestinationButton *btn = m_destination_button_list.at(floorNumber);
    if(btn->getState()==1) {
        btn->setState(0);
    }
}

void DestinationPanel::floorClick(int floorNumber)
{
    DestinationButton *btn = m_destination_button_list.at(floorNumber);
    btn->setState(1);
}
