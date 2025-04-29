#ifndef DISPLAY_H
#define DISPLAY_H
#include "sphere.h"


class Display {
public:
    int width = 101;
    int height = 35;
    float eye_x = 0;
    float eye_y = 0;
    float eye_z = 0;
    float d = 0;
    float start_ray_point = 1;
    float end_ray_point = 1000;
    char *arr_of_simbols[2] = {".", "@"};
    Sphere *sphere;

    char** mtx;


    Display();

    ~Display();

    void show();


private:
    struct intersections {
        float t1;
        float t2;
    };

    void set_simbols_to_mtx();

    void set_simbol_to_element(int x, int y);

    char choose_simnbol_to_element(int x, int y);

    struct intersections ray_tracing(int x, int y);
    
    int to_central_coords(int val, int range);

};

#endif