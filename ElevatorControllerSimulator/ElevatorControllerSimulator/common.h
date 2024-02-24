#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum Direction {
    UP,
    DOWN,
    IDEL
};

inline static QString style_light = QString("background-color: rgb(250,250, 5)");
inline static QString style_default = "";

class Common {
public:
    static int floorCount;
    static int elevatorCount;
    static int maxWeight;
};


#endif // COMMON_H
