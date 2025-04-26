#include "display.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include "vector3.h"
#include "sphere.h"
using namespace std;

struct roots_of_quadraic {
    int t1;
    int t2;
}

Display::Display() {
    Sphere sphere1(18, 57, 14, 5); 

    hieght;
    width;
    mtx = new char*[hieght];
    x_coords = new int[width];
    y_coords = new int[hieght];
    for (int i = 0; i<hieght; i++) {
        mtx[i] = new char[width];
        for (int j = 0; j<width; j++) {
            mtx[i][j] = '.';
        }
    }
}

Display::~Display() {
    cout << "deleted" << endl;
}

void Display::show() {
    set_coords();
    for (int k = 0; k < 1; k++) {
        for (int i = 0; i<hieght; i++) {
            print_coord(y_coords[i]);
            cout << " ";
            for (int j = 0; j<width; j++) {
                cout << mtx[i][j];
            }
            cout << endl;
        }
        usleep(250000); //1000000 mks = 1 s
        cout << "  ";
        for (int i = 0; i < width; i++) {
            print_coord(x_coords[i]);
        }
        cout << endl;
        cout << endl;
    }

}

void Display::set_coords() {
    int k = 0;
    for (int i = -((width-1)/2); i < (width+1)/2; i++) {
        x_coords[k] = i;
        k++;
    }
    k = 0;
    for (int j = -((hieght-1)/2); j < (hieght+1)/2; j++) {
        y_coords[k] = j;
        k++;
    }
}

void Display::print_coord(int val) {
    if (val < 0) {
        cout << "-";
    } else if (val == 0) {
        cout << "0";
    } else {
        cout << "+";
    }
}

int Display::get_center_coordinate(int coord_val, int interval){
    if (coord_val < (interval-1)/2) {
        return -(coord_val);
    } else if (coord_val > (interval+1)/2) {
        return coord_val - (interval+1)/2;
    } else if (coord_val = (interval-1)/2 + 1) {
        return 0;
    }
    return 0;
}

int Display::get_left_top_coordinate(int coord_val, int interval){
    if (coord_val < 0) {
        return abs(coord_val);
    } else if (coord_val == 0) {
        return (interval-1)/2 + 1;
    } else if (coord_val > 0) {
        return coord_val + (interval+1)/2;
    }
}

void Display::set_matrix(int x, int y, char simbol) {
    mtx[x][y] = simbol;
}

Vector3 *Display::display_to_viewport(int x, int y){
    Vector3 *res_v = new Vector3(x, y, d);
    return res_v;
}

char Display::simbol_of_ray_trace(){

}

int *Display::intersect_ray_sphere(Vector3 *O, Vector3 *D, Sphere *sphere){
    Vector3 C(sphere.center_x, sphere.center_y, sphere.center_z);
    int r = sphere->radius;
    Vector3 OC(O->x - C->x, O->y - C->y, O->z - C->z);

    Vector3 *tmp1 = D->scalar_product_of_vectors_this_and_v2(*D);
    int k1 = tmp1->len_of_vector3();
    Vector3 *tmp2 = OC.scalar_product_of_vectors_this_and_v2(D);
    int k2 = 2*tmp2->len_of_vector3();
    Vector3 *tmp3 = OC.scalar_product_of_vectors_this_and_v2(OC);
    int k3 = tmp3->len_of_vector3() - pow(r, 2);

    discriminant = pow(k2, 2) - 4*k1*k3;
    struct roots_of_quadraic ret_roots;
    if (discriminant < 0) {
        ret_roots.t1 = 0;
        ret_roots.t2 = 0;
    } else {
        t1 = (-k2 + sqrt(discriminant))/(2*k1);
        t2 = (-k2 - sqrt(discriminant))/(2*k1);
        ret_roots.t1 = t1;
        ret_roots.t2 = t2;
    }
    return &ret_roots;
}