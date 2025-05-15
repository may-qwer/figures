#ifndef DISPLAY_H
#define DISPLAY_H
#include "vector2.h"
#include "vector3.h"
#include "sphere.h"


class Display {
public:
    int HEIGHT = 23;
    int WIDTH = 79;
    float PIXEL_WIDTH = 9.0;
    float PIXEL_HEIGHT = 18.0;
    float SCALE;
    float SIMBOL_SCALE;
    int LEN_ARR_OF_SIMBOLS = 17;
    char *ARR_OF_SIMBOLS;
    Vector3 *EYE;
    Vector3 *D;
    Sphere *sphere1;
    Vector3 *light;

    char** mtx;

    Display();

    ~Display();

    void show();

private:

    void set_simbol_to_el(Vector2 *uv);

    char make_curcle(Vector2 *uv, float x0 = 0.0, float y0 = 0.0);

    char make_sphere(Vector3 *D);
};

#endif