#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>

class Display : public QObject
{
    Q_OBJECT
public:
    explicit Display(QObject *parent = nullptr);

    void updateMessage(QString message);

signals:

private:
    // current message;
    QString message;
};

#endif // DISPLAY_H
