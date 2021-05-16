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
        x = 111.321 * longitude * cos(latitude * M_PI / 180);
        y = 111.135 * latitude;
    }

    Point(){}

    Point(double lat, double lon){
        latitude = lat;
        longitude = lon;
        x = 111.321 * longitude * cos(latitude * M_PI / 180);
        y = 111.135 * latitude;
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

        x = 111.321 * longitude * cos(latitude * M_PI / 180);
        y = 111.135 * latitude;

        // return Point(x, y, type, subtype, name, address);
    }

};
