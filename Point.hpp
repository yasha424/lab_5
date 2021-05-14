#include <iostream>
#include <string>
#include <cmath>

class Point{
    double longitude;
    double latitude;
    std::string type;
    std::string subtype;
    std::string name;
    std::string adress;
public:
    // это должны быть координаты без искажения
    double x;
    double y;

    Point(){}
    Point(double, double, std::string, std::string, std::string, std::string);

    double getLongitude(){ return longitude; }
    double getLatitude(){ return latitude; }
    std::string getType(){ return type; }
    std::string getSubtype(){ return subtype; }
    std::string getName(){ return name; }
    std::string getAdress(){ return adress; }

    void print();

    // функция, которая будет возвращать расстаяние до точки
    double distance(double, double);
};
