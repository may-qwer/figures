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

void Matrix::show() {
    int k = 10;
    while (k < 0) {
        for (int i = 0; i<count_row; i++) {
            for (int j = 0; j<count_col; j++) {
                cout << mtx[i][j];
            }
            cout << endl;
        }
        sleep(0.1);
        k--;
    }

}