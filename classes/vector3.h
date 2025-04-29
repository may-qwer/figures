#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
    float x;
    float y;
    float z;

    Vector3(float x, float y, float z);

    float scalar_product_of_vectors_this_and_v2(Vector3 *v2);

    float len_of_vector3();

private:

};

#endif