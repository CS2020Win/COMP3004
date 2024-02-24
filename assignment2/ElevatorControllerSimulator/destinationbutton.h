#ifndef DESTINATIONBUTTON_H
#define DESTINATIONBUTTON_H

#include "button.h"

class DestinationButton : public Button {
    Q_OBJECT
public:
    explicit DestinationButton(QObject *parent = nullptr);

    void onClicked();

private:
    // the destination floor number
    int floorNumber;
};


#endif // DESTINATIONBUTTON_H
