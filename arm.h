#ifndef ARM_H
#define ARM_H

#include "joint.h"

#include <QList>
#include <gl.h>

class Arm
{
public:
    Arm();
    Arm(QList<Joint> jointList);

    QList<Joint> *getJointList();

    void setJointList(QList<Joint> jointList);
    void draw();
private:
    QList<Joint> jointList;
};

#endif // ARM_H
