#include <iostream>
#include "Point.hpp"
using namespace std;

int main(int args, char** argz){
    Point point(10, 20, "type", "subtype", "name", "adress");
    // cout << point.getLatitude() << endl;
    // cout << point.getLongitude() << endl;
    // cout << point.getType() << endl;
    // cout << point.getSubtype() << endl;
    // cout << point.getName() << endl;
    // cout << point.getAdress() << endl;
    point.print();
}
