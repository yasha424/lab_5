#include <iostream>
#include <string>
using namespace std;

class Point{
public:
    double x, y;
    string type, subtype,
           name, address;

    Point(double _x,double _y, string _type, string _subtype, string _name, string _address){
        x = _x;
        y = _y;
        type = _type;
        subtype = _subtype;
        name = _name;
        address = _address;
    }
};

class Rectangle{
public:
    double x, y, width, height;

    Rectangle(double _x, double _y, double w, double h){
        x = _x;
        y = _y;
        width = w;
        height = h;
    }
};
