#include "matrix.h"
#include <unistd.h> 
#include <iostream>
#include <math.h>
#include <cmath.h>
using namespace std;

int count_col = 25;

Matrix::Matrix() {
    for (int i = 0; i<count_row; i++) {
        for (int j = 0; j<count_col; j++) {
            mtx[i][j] = '-';
        }
    }
}

Matrix::~Matrix() {

}

void Matrix::add_to_x_y_ranges() {
    int k = 0;
    for (int i = center_x - circle_radius; i <= center_x + circle_radius + 1; i++) {
        x_range_for_circle[k] = i;
        k++;
    }
    for (int i = 0; i < 8; i++) {
        int y = static_cast<int>(round(sqrt((center_x + circle_radius) * (center_x + circle_radius) - x_range_for_circle[i] * x_range_for_circle[i])));
        y_range_for_circle[i] = center_y + y;
    }
    k = 0;
}

char *Matrix::make_circle() {
    // y2 = 1-x2
}

void Matrix::show() {
    int k = 1;
    add_to_x_y_ranges();
    while (k > 0) {
        make_circle();
        for (int i = 0; i<count_row; i++) {
            for (int j = 0; j<count_col; j++) {
                cout << mtx[i][j];
            }
            cout << endl;
        }
        sleep(1);
        k--;
        cout << endl;
    }

}