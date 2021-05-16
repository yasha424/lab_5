#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
using namespace std;



class Rectangle{
public:
    double x1, y1, x2, y2;
    double X1, Y1, X2, Y2;

    Rectangle(){}

    Rectangle(double _x1, double _y1, double _x2, double _y2){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }

    bool contains(Point point){
        return (x1 <= point.latitude && y1 <= point.longitude && point.latitude < x2 && point.longitude < y2);
    }
};

class Circle{
public:
    double x, y, latitude, longitude, radius;

    Circle(Point point, double rad){
        x = point.x;
        y = point.y;
        latitude = point.latitude;
        longitude = point.longitude;
        radius = rad;
    }
};
