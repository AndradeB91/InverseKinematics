#include "util.h"

Util::Util()
{
}

vec2 Util::rotation(vec2 v,float angle){
    angle *= 0.0174533;
    vec2 res(cos(angle)*v.x - sin(angle)*v.y, sin(angle)*v.x + cos(angle)*v.y);
    return res;
}
