#include "sphere.h"
#include <math.h>
#include <iostream>


Sphere::Sphere(float x, float y, float z, float r) {    
    center_v3 = new Vector3(x, y, z);
    this->radius = r;
}

Vector2 *Sphere::get_points(Vector3 *EYE, Vector3 *D) {
    float b = EYE->scalar_product_of_vectors_this_and_v2(D); 
    float c = EYE->scalar_product_of_vectors_this_and_v2(EYE) - (float)pow(this->radius, 2); 
    float h = pow(b, 2) - c;
    Vector2 *res = new Vector2(0.0, 0.0);
    if (h < 0.0) {
        res->x = -1.0; 
        res->y = -1.0;
    } else {
        h = sqrt(h);
        res->x = -b - h;
        res->y = -b + h;
    }
    return res;
}
