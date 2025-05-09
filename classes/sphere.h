#ifndef SPHERE_H
#define SPHERE_H
#include "vector3.h"
#include "vector2.h"

class Sphere {
public:
    int radius;
    Vector3 *center_v3;

    Sphere(int r, int x, int y, int z);

    Vector2 *get_points(Vector3 * EYE, Vector3 *D);

private:

};

#endif