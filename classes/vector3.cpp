#include "vector3.h"

Vector3::Vector3(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 *Vector3::scalar_product_of_vectors_this_and_v2(Vector3 *v2) {
    Vector3 *res_v = new Vector3(this->x*v2->x, this->y*v2->y, this->z*v2->z);
    return res_v;
}