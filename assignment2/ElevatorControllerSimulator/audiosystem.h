#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include <QObject>

class AudioSystem : public QObject
{
    Q_OBJECT
public:
    explicit AudioSystem(QObject *parent = nullptr);

    void play();

};

#endif // AUDIOSYSTEM_H
