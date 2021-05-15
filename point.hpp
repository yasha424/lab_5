#pragma once

#include <string>
#include <cmath>
using namespace std;

class Point{
public:
    double x, y, latitude, longitude;
    string type, subtype,
           name, address;

    Point(double _x,double _y, string _type, string _subtype, string _name, string _address){
        latitude = _x;
        longitude = _y;
        type = _type;
        subtype = _subtype;
        name = _name;
        address = _address;
        x = 6371 * cos(latitude * 3.14159 / 180) * (longitude * 3.14159 / 180);
        y = (latitude * 3.14159 / 180) * 6371;
    }

    Point(){}

    Point(double lat, double lon){
        latitude = lat;
        longitude = lon;
        x = 6371 * cos(latitude * 3.14159 / 180) * (longitude * 3.14159 / 180);
        y = (latitude * 3.14159 / 180) * 6371;
    }

    void setPoint(string s){
        while(s.find(',') != -1)
            s[s.find(',')] = '.';
        latitude = stof(s.substr(0, s.find(';')));
        s = s.substr(s.find(';') + 1);
        longitude = stof(s.substr(0, s.find(';')));
        s = s.substr(s.find(';') + 1);
        type = s.substr(0, s.find(';'));
        s = s.substr(s.find(';') + 1);
        subtype = s.substr(0, s.find(';'));
        s = s.substr(s.find(';') + 1);
        name = s.substr(0, s.find(';'));
        s = s.substr(s.find(';') + 1);
        address = s.substr(0, s.find(';'));

        x = 6371 * cos(latitude * 3.14159 / 180) * (longitude * 3.14159 / 180);
        y = (latitude * 3.14159 / 180) * 6371;

        // return Point(x, y, type, subtype, name, address);
    }

};
