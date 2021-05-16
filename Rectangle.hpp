#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
using namespace std;



class Rectangle{
public:
    double lat1, long1, lat2, long2;
    double x1, y1, x2, y2;

    Rectangle(){}

    Rectangle(double _x1, double _y1, double _x2, double _y2){
        lat1 = _x1;
        long1 = _y1;
        lat2 = _x2;
        long2 = _y2;
        x1 = 111.321 * long1 * cos(lat1 * M_PI / 180);
        y1 = 111.135 * lat1;
        x2 = 111.321 * long2 * cos(lat2 * M_PI / 180);
        y2 = 111.135 * lat2;
    }

    bool contains(Point point){
        return (x1 <= point.x && y1 <= point.y && point.x < x2 && point.y < y2);
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
