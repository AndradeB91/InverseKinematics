#ifndef UTIL_H
#define UTIL_H

#include "glm/glm/glm.hpp"

using namespace glm;

class Util
{
public:
    Util();
    static vec2 rotation(vec2 v,float angle);
};

#endif // UTIL_H
