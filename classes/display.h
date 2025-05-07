#ifndef DISPLAY_H
#define DISPLAY_H


class Display {
public:
    int HEIGHT = 23;
    int WIDTH = 79;
    float SCALE;
    float SIMBOL_SCALE;
    char** MTX;

    Display();

    ~Display();

    void show();

private:

    void set_simbol_to_el(int x, int y, int x0, int y0);

    char make_curcle(float x, float y, float x0, float y0);


};

#endif