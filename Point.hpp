#include <iostream>
#include <string>

class Point{
    double latitude;
    double longitude;
    std::string type;
    std::string subtype;
    std::string name;
    std::string adress;

public:
    Point(){}
    Point(double, double, std::string, std::string, std::string, std::string);

    double getLatitude(){ return latitude; }
    double getLongitude(){ return longitude; }
    std::string getType(){ return type; }
    std::string getSubtype(){ return subtype; }
    std::string getName(){ return name; }
    std::string getAdress(){ return adress; }

    void print();
};
