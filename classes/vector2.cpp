#include "vector2.h"
#include <math.h>

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}


Vector2::Vector2(int val) {
    this->x = val;
    this->y = val;
}

float Vector2::scalar_product_of_vectors_this_and_v2(Vector2 *v2) {
    return this->x * v2->x + this->y * v2->y;
}

float Vector2::len_of_vector2(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

void Vector2::normalize() {
     float len = len_of_vector2();
     this->x = this->x/len;
     this->y = this->y/len;
}

void Vector2::sum(Vector2 *v2){
    this->x += v2->x;
    this->y += v2->y;
}

void Vector2::sum(float num) {
    this->x += num;
    this->y += num;
}

void Vector2::prod(Vector2 *v2){
    this->x *= v2->x;
    this->y *= v2->y;
}

void Vector2::prod(float num) {
    this->x *= num;
    this->y *= num;
}

void Vector2::divis(float num) {
    this->x /= num;
    this->y /= num;
}

void Vector2::divis(int num) {
    this->x /= num;
    this->y /= num;
}
