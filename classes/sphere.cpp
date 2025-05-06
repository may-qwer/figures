#include "sphere.h"
#include "vector3.h"

Sphere::Sphere(int x, int y, int z, int r) {    
    center_v3 = new Vector3(x, y, z);
    this->radius = r;
}
