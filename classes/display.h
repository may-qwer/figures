#ifndef DISPLAY_H
#define DISPLAY_H


class Display {
public:
    int width = 101;
    int hieght = 35;
    char** mtx;


    Display();

    ~Display();

    void show();

    int get_center_coordinate(int coord_val, int interval);

    int get_left_top_coordinate(int coord_val, int interval);

private:
    int* x_coords;
    int* y_coords;
    
    void set_coords();

    void print_coord(int val);
};

#endif