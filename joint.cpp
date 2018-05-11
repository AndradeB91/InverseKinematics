#include "joint.h"

Joint::Joint()
{
}

Joint::Joint(vec2 pos){
    this->pos = pos;
}

void Joint::setPos(vec2 pos){
    this->pos = pos;
}

vec2 Joint::getPos(){
    return this->pos;
}
