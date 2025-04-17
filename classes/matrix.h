#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    int count_col = 25;
    int count_row = 25;
    char mtx[25][25];

    Matrix();

    ~Matrix();

    char *get_matrix();

    void create_matrix();

    void show();

private:


};

#endif