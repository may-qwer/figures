#ifndef DISPLAY_H
#define DISPLAY_H
#include "sphere.h"
#include "vector3.h"


class Display {
public:
    int WIDTH = 101;
    int HEIGHT = 35;
    Vector3 *EYE;
    int D = 2;
    int START_RAY_POINT = 0;
    int END_RAY_POINT = 100;
    int MAX_COUNT_STAPS = 255;
    char *ARR_OF_SIMBOLS[2] = {".", "@"};
    Sphere *sphere;
    char** MTX;
    float EPSILON = 0.0001;

    Display();

    ~Display();

    void show();


private:

    void set_simbols_to_mtx();

    void set_simbol_to_element(int x, int y);

    char choose_simnbol_to_element(int x, int y);

    float ray_trace(Vector3 *ray_dir);
    
    int to_central_coords(int val, int range);

    float get_sdf(Vector3 *point, int radius);

};

#endif