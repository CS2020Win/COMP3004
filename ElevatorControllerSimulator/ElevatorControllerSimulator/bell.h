#ifndef BELL_H
#define BELL_H

#include <QObject>

class Bell : public QObject
{
    Q_OBJECT
public:
    explicit Bell(QObject *parent = nullptr);

    void ring(int seconds);

};


#endif // BELL_H
