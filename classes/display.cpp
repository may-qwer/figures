#include "display.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include "vector3.h"

using namespace std;


Display::Display() {
    sphere = new Sphere(5, 17, 55, 2); 
    EYE = new Vector3(0, 0, 0);

    HEIGHT;
    WIDTH;
    MTX = new char*[HEIGHT];
    for (int i = 0; i<HEIGHT; i++) {
        MTX[i] = new char[WIDTH];
    }
}

Display::~Display() {
    cout << "deleted" << endl;
}

void Display::show() {
    set_simbols_to_mtx();
    for (int i = 0; i<HEIGHT; i++) {
        cout << " ";
        for (int j = 0; j<WIDTH; j++) {
            cout << MTX[i][j];
        }
        cout << endl;
    }
}

void Display::set_simbols_to_mtx() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            set_simbol_to_element(i, j);
        }
    }
}

void Display::set_simbol_to_element(int x, int y) {
    MTX[x][y] = choose_simnbol_to_element(x, y);
}

char Display::choose_simnbol_to_element(int x, int y) {
    // Vector3 ray_dir(to_central_coords(x, WIDTH) - EYE->x, to_central_coords(y, HEIGHT) - EYE->y, D - EYE->z);
    Vector3 ray_dir(x - EYE->x, y- EYE->y, D - EYE->z);
    ray_dir.normalize();

    float dist = ray_trace(&ray_dir);
    if (dist > END_RAY_POINT - EPSILON) {
        return *ARR_OF_SIMBOLS[0];
    }
    return *ARR_OF_SIMBOLS[1];
}

float Display::ray_trace(Vector3 *ray_dir) {
    float depth = START_RAY_POINT;
    for (int i = 0; i < MAX_COUNT_STAPS; i++) {
        Vector3 ray(sphere->x + depth*ray_dir->x, sphere->y + depth*ray_dir->y, sphere->z + depth*ray_dir->z);
        float dist = get_sdf(&ray, sphere->radius);
        if (dist < EPSILON) {
            return depth;
        }
        depth += dist;
        if (depth >= END_RAY_POINT) {
            return END_RAY_POINT;
        }
    }
    return END_RAY_POINT;
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

float Display::get_sdf(Vector3 *point, int radius) {
    return point->len_of_vector3() - radius;
}
