#include <iostream>
#include "Point.hpp"
using namespace std;

int main(int args, char** argz){
    Point point(34.159, 50.2354, "type", "subtype", "name", "adress");
    point.print();
    // cout << fixed << point.x << ", " << fixed << point.y << endl;
}
