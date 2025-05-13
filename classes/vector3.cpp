#include "vector3.h"
#include <math.h>
#include <iostream>

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(int val) {
    this->x = val;
    this->y = val;
    this->z = val;
}

float Vector3::scalar_product_of_vectors_this_and_v2(Vector3 *v2) {
    return this->x * v2->x + this->y * v2->y + this->z * v2->z;
}

float Vector3::len_of_vector3(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

void Vector3::normalize() {
     float len = len_of_vector3();
     this->x /= len;
     this->y /= len;
     this->z /= len;
}

void Vector3::sum(Vector3 *v2){
    this->x += v2->x;
    this->y += v2->y;
    this->z += v2->z;
}

void Vector3::sum(int num) {
    this->x += num;
    this->y += num;
    this->z += num;
}

void Vector3::prod(float val) {
    this->x *= val;
    this->y *= val;
    this->z *= val;
}

void Vector3::diff(Vector3 *v2){
    this->x -= v2->x;
    this->y -= v2->y;
    this->z -= v2->z;
}

void Vector3::diff(float num) {
    this->x -= num;
    this->y -= num;
    this->z -= num;
}

void Vector3::print_v3() {
    std::cout << "x: " << this->x << " y: " << this->y << " z: " << this->z << std::endl;
}
