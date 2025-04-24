#include <iostream>
#include <unistd.h> 
#include "./classes/display.h"
using namespace std;

int main() {
    Display display;
    display.show();
    cout << display.get_center_coordinate(35, 101) << endl;
    cout << display.get_center_coordinate(51, 101) << endl;
    cout << display.get_center_coordinate(75, 101) << endl;
    cout << endl;
    cout << display.get_left_top_coordinate(-35, 101) << endl;
    cout << display.get_left_top_coordinate(0, 101) << endl;
    cout << display.get_left_top_coordinate(24, 101) << endl;

    return 0;
}