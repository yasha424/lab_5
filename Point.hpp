#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point{
    double longitude;
    double latitude;
    string type;
    string subtype;
    string name;
    string adress;
public:
    // это должны быть координаты без искажения
    double x;
    double y;

    Point(){}
    Point(double, double, string, string, string, string);

    double getLongitude(){ return longitude; }
    double getLatitude(){ return latitude; }
    string getType(){ return type; }
    string getSubtype(){ return subtype; }
    string getName(){ return name; }
    string getAdress(){ return adress; }

    void print();

    // функция, которая будет возвращать расстаяние до точки
    double distance(double, double);
    void make_point(string); // надо написать
};
