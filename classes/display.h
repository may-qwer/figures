#ifndef DISPLAY_H
#define DISPLAY_H

struct roots_of_quadraic;

class Display {
public:
    int width = 101;
    int hieght = 35;
    int eye_x = 0;
    int eye_y = 0;
    int eye_z = 0;
    int d = 1;
    int start_ray_point = 1;
    int end_rat_point = 1000;
    char *arr_of_simbols[2] = {".", "@"}

    char** mtx;


    Display();

    ~Display();

    void show();

    int get_center_coordinate(int coord_val, int interval);

    int get_left_top_coordinate(int coord_val, int interval);

    void set_matrix(int x, int y, char simbol);

    char simbol_of_ray_trace();

private:
    int* x_coords;
    int* y_coords;
    
    void set_coords();

    void print_coord(int val);

    Vector3 *display_to_viewport(int x, int y);

    struct roots_of_quadraic *intersect_ray_sphere(Vector3 *O, Vector3 *D, Sphere *sphere);
};

#endif