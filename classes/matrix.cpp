#include "matrix.h"
#include <unistd.h> 
#include <iostream>
using namespace std;

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
    for (int i = center_x - circle_radius - 1; i <= center_x + circle_radius + 1; i++) {
        x_range_for_circle[k] = i;
        k++;
    }
    k = 0;
    for (int j = center_y - circle_radius - 1; j <= center_y + circle_radius + 1; j++) {
        y_range_for_circle[k] = j;
        k++;
    }
}

char *Matrix::make_circle() {
    // y2 = 1-x2
}

void Matrix::show() {
    int k = 10;
    add_to_x_y_ranges();
    while (k > 0) {
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