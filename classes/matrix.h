#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    int count_col = 25;
    int count_row = 13;
    int center_x = 13;
    int center_y = 7;
    int circle_radius = 4;
    int x_range_for_circle[9];// = {9, 10, 11, 12, 13, 14, 15, 16, 17}    
    int y_range_for_circle[9];

    char mtx[25][25];

    Matrix();

    ~Matrix();



    char *make_circle();

    void show();

private:
    void add_to_x_y_ranges();

};

#endif