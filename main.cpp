#include <iostream>
#include <unistd.h> 
#include "./classes/display.h"
#include "./classes/vector3.h"
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

    Vector3 v1(2, 3, 4);
    Vector3 v2(4, 5, 6);

    Vector3 res_v = *(v1.scalar_product_of_vectors_this_and_v2(&v2));
    cout << res_v.x << " " << res_v.y << " " << res_v.z << " " << endl;

    return 0;
}