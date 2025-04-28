#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
    int x;
    int y;
    int z;

    Vector3(int x, int y, int z);

    int scalar_product_of_vectors_this_and_v2(Vector3 *v2);

    int len_of_vector3();

private:

};

#endif