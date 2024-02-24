#ifndef DESTINATIONBUTTON_H
#define DESTINATIONBUTTON_H

#include "button.h"

class DestinationButton : public Button {
    Q_OBJECT
public:
    explicit DestinationButton(int floorNumber, QObject *parent = nullptr);

    int getState();

    void setState(int state);

    void onClick();

signals:
    void onClicked(int floorNumber);

private:
    // the destination floor number
    int floorNumber;

    int m_state;
};

#endif // DESTINATIONBUTTON_H
