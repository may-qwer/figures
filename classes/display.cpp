#include "display.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include "vector3.h"

using namespace std;


Display::Display() {
    sphere = new Sphere(30, 50, 14, 20); 

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
    int t1 = t12.t1;
    int t2 = t12.t2;
    if ((t1 > start_ray_point && t1 < end_ray_point) || (t2 > start_ray_point && t2 < end_ray_point)) {
        return *arr_of_simbols[1];
    }
    return *arr_of_simbols[0];
}

Display::intersections Display::ray_tracing(int x, int y) {
    struct intersections t12;
    t12.t1 = 0;
    t12.t2 = 0;

    int r = sphere->radius;
    Vector3 D(x - O.x, y - O.y, d - O.z);
    Vector3 OC(eye_x - sphere->center_x, eye_y - sphere->center_y, eye_z - sphere->center_z);

    int k1 = D.scalar_product_of_vectors_this_and_v2(&D);
    int k2 = 2*OC.scalar_product_of_vectors_this_and_v2(&D);
    int k3 = OC.scalar_product_of_vectors_this_and_v2(&OC) - pow(r, 2);
        
    int discriminant = pow(k2, 2) - 4*k1*k3;
    if (discriminant >= 0) {
        t12.t1 = (-k2 + sqrt(discriminant)) / (2*k1);
        t12.t2 = (-k2 - sqrt(discriminant)) / (2*k1);
    }
    return t12;
}
