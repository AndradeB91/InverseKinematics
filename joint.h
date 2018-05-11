#ifndef JOINT_H
#define JOINT_H

#include "glm/glm/glm.hpp"

using namespace glm;

class Joint
{
public:
    Joint();
    Joint(vec2 pos);
    void setPos(vec2 pos);

    vec2 getPos();
private:
    vec2 pos;
};

#endif // JOINT_H
