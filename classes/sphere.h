#ifndef SPHERE_H
#define SPHERE_H
#include "vector3.h"
#include "vector2.h"

class Sphere {
public:
    float radius;
    Vector3 *center_v3;

    Sphere(float x, float y, float z, float r);

    Vector2 *get_points(Vector3 * EYE, Vector3 *D);

private:

};

#endif