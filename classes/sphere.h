#ifndef SPHERE_H
#define SPHERE_H
#include "vector3.h"

class Sphere {
public:
    int radius;
    Vector3 *center_v3;

    Sphere(int r, int x, int y, int z);

private:

};

#endif