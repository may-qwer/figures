#include "display.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include "vector3.h"
#include "vector2.h"


using namespace std;


Display::Display() {
    HEIGHT;
    WIDTH;
    PIXEL_WIDTH;
    PIXEL_HEIGHT;
    SCALE = (float)WIDTH/HEIGHT;
    SIMBOL_SCALE = (float)PIXEL_WIDTH/PIXEL_HEIGHT;
    LEN_ARR_OF_SIMBOLS;
    ARR_OF_SIMBOLS = new char[LEN_ARR_OF_SIMBOLS] {' ', '.', ':', '!', '/', 'r', '(', 'l', '1', 'Z', '4', 'H', '9', 'W', '8', '$', '@'};//{' ', '.', ',', '~', '=', '#'};
    EYE = new Vector3(-5.0, 0.0, 0.0);
    D = new Vector3(0.0, 0.0, 0.0);
    sphere1 = new Sphere(0.0, 0.0, 0.0, 2.0);

    mtx = new char*[WIDTH];
    for (int i = 0; i<WIDTH; i++) {
        mtx[i] = new char[HEIGHT];
    }
}

Display::~Display() {
    cout << "end" << endl;
}

void Display::show() {
    for (int t = 0; t < 1; t++){
        usleep(25000);
        for (int y = 0; y<HEIGHT; y++) {
            for (int x = 0; x<WIDTH; x++) {
                Vector2 uv(x, y);
                set_simbol_to_el(&uv);
                cout << mtx[x][y];
            }
            cout << endl;
        }
    }
}

void Display::set_simbol_to_el(Vector2 *uv) {
    int x = uv->x;
    int y = uv->y;
    uv->x /= WIDTH;
    uv->y /= HEIGHT;
    uv->prod(2.0);
    uv->sum(-1.0);
    uv->x *= SCALE * SIMBOL_SCALE;
    D->x = 1.0;
    D->y = uv->x;
    D->z = uv->y;
    D->normalize();
    // cout << D->x << " " << D->y << " " << D->z << endl;

    // mtx[x][y] = make_curcle(uv);
    mtx[x][y] = make_sphere(D);
}


char Display::make_curcle(Vector2 *uv, float x0, float y0) {
    float dist = pow(uv->x - x0, 2) + pow(uv->y - y0, 2);
    int color = (int)(1.0/dist);
    if (color < 0) {
        return ARR_OF_SIMBOLS[0];
    } else if (color > LEN_ARR_OF_SIMBOLS) {
        return ARR_OF_SIMBOLS[LEN_ARR_OF_SIMBOLS-1];
    }
    return ARR_OF_SIMBOLS[color];
}

char Display::make_sphere(Vector3 *D) {
    // Vector3 eye_with_sphere_coords(EYE->x, EYE->y, EYE->z);
    // eye_with_sphere_coords.diff(sphere1->center_v3);
    Vector2 *intersection = sphere1->get_points(EYE, D);
    if (intersection->x > 0) {
        return '@';
    }
    return ' ';
}

