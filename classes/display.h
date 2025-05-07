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

    void set_simbol_to_el(int x, int y);

    char make_curcle(float x, float y);

};

#endif