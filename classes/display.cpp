#include "display.h"
#include <unistd.h> 
#include <iostream>
using namespace std;

int count_col = 25;

Display::Display() {
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