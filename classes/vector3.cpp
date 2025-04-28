#include "vector3.h"
#include <math.h>

Vector3::Vector3(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

int Vector3::scalar_product_of_vectors_this_and_v2(Vector3 *v2) {
    return this->x * v2->x + this->y * v2->y + this->z * v2->z;
}

int Vector3::len_of_vector3(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}