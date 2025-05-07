#include "display.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include "vector3.h"


using namespace std;


Display::Display() {
    HEIGHT;
    WIDTH;
    SCALE = (float)WIDTH/HEIGHT;
    SIMBOL_SCALE = 9.0/18.0;
    MTX = new char*[WIDTH];
    for (int i = 0; i<WIDTH; i++) {
        MTX[i] = new char[HEIGHT];
    }
}

Display::~Display() {
    cout << "deleted" << endl;
}

void Display::show() {
    int k = 0;
    int diff;
    for (int t = 0; t < 400; t++){
        usleep(25000);
        if (k == WIDTH) {
            diff = -1;
        } else if (k == 0) {
            diff = 1;
        }
        k += diff;
        for (int y = 0; y<HEIGHT; y++) {
            for (int x = 0; x<WIDTH; x++) {
                set_simbol_to_el(x, y, k, HEIGHT);
                cout << MTX[x][y];
            }
            cout << endl;
        }
    }
}

void Display::set_simbol_to_el(int x, int y, int x0, int y0) {
    float x_1 = (float)x / WIDTH * 2.0 - 1.0;
    float y_1 = (float)y / HEIGHT *2.0 - 1.0;
    x_1 = x_1 * SCALE * SIMBOL_SCALE;
    float x0_1 = (float)x0 / WIDTH * 2.0 - 1.0;
    float y0_1 = (float)y0 / HEIGHT - 1.0;
    x0_1 = x0_1 * SCALE * SIMBOL_SCALE;
    MTX[x][y] = make_curcle(x_1, y_1, x0_1, y0_1);
}


char Display::make_curcle(float x, float y, float x0, float y0) {
    if (pow(x- x0, 2) + pow(y - y0, 2) < 0.5) {
        return '@';
    }
    return '.';
}

