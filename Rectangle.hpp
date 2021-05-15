#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
using namespace std;



class Rectangle{
public:
    double x1, y1, x2, y2/*, width, height*/;

    Rectangle(){}

    Rectangle(double _x1, double _y1, double _x2, double _y2/*, double w, double h*/){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }

    bool contains(Point point){
        return (x1 <= point.x && y1 <= point.y && point.x < x2 && point.y < y2);
    }
};
