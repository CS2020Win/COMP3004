#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>

class Button : public QObject
{
    Q_OBJECT
public:
    explicit Button(QObject *parent = nullptr);

    virtual void click();

signals:
    void onClicked();

};

#endif // BUTTON_H
