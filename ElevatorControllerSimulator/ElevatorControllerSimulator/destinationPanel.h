#ifndef DESTINATIONPANEL_H
#define DESTINATIONPANEL_H

#include <QObject>
#include <QList>

#include "destinationbutton.h"

class DestinationPanel : public QObject
{
    Q_OBJECT
public:
    explicit DestinationPanel(QObject *parent = nullptr);

    DestinationButton* getButton(int floorNumber);

public slots:
    void newFloor(int floorNumber);

    void floorClick(int floorNumber);

private:
    QList<DestinationButton*> m_destination_button_list;
};

#endif // DESTINATIONPANEL_H
