#include "display.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include "vector3.h"

using namespace std;


Display::Display() {
    sphere = new Sphere(17, 50, 0, 5); 

    height;
    width;
    mtx = new char*[height];
    for (int i = 0; i<height; i++) {
        mtx[i] = new char[width];
    }
}

Display::~Display() {
    cout << "deleted" << endl;
}

void Display::show() {
    set_simbols_to_mtx();
    for (int i = 0; i<height; i++) {
        cout << " ";
        for (int j = 0; j<width; j++) {
            cout << mtx[i][j];
        }
        cout << endl;
    }
}

void Display::set_simbols_to_mtx() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            set_simbol_to_element(i, j);
        }
    }
}

void Display::set_simbol_to_element(int x, int y) {
    mtx[x][y] = choose_simnbol_to_element(x, y);
}

char Display::choose_simnbol_to_element(int x, int y) {
    struct intersections t12 = ray_tracing(x, y);
    float t1 = t12.t1;
    float t2 = t12.t2;
    cout << t1 << " " << t2 << endl;
    if ((t1 > start_ray_point && t1 < end_ray_point) || (t2 > start_ray_point && t2 < end_ray_point)) {
        return *arr_of_simbols[1];
    }
    return *arr_of_simbols[0];
}

Display::intersections Display::ray_tracing(int x, int y) {
    struct intersections t12;
    t12.t1 = 0;
    t12.t2 = 0;

    Vector3 O(to_central_coords(eye_x, width), to_central_coords(eye_y, height),eye_z);
    Vector3 C(to_central_coords(sphere->center_x, width), to_central_coords(sphere->center_y, height), sphere->center_z);
    float r = sphere->radius;
    
    Vector3 D(to_central_coords(x, width) - O.x, to_central_coords(y, height) - O.y, d - O.z);
    int len_d = D.len_of_vector3();
    if (len_d != 0) {
        D.x /= len_d;
        D.y /= len_d;
        D.z /= len_d;
    }
    Vector3 OC(O.x - C.x, O.y - C.y, O.z - C.z);

    float k1 = D.scalar_product_of_vectors_this_and_v2(&D);
    float k2 = 2*OC.scalar_product_of_vectors_this_and_v2(&D);
    float k3 = OC.scalar_product_of_vectors_this_and_v2(&OC) - pow(r, 2);
        
    float discriminant = pow(k2, 2) - 4*k1*k3;
    if (discriminant >= 0) {
        t12.t1 = (-k2 + sqrt(discriminant)) / (2*k1);
        t12.t2 = (-k2 - sqrt(discriminant)) / (2*k1);
    }
    return t12;
}

int Display::to_central_coords(int val, int range) {
    int center = ((range - 1) / 2) + 1;
    if (val < center) {
        return -val;
    } else if (val == center) { 
        return 0;
    } else {
        return val - center;
    }
}
