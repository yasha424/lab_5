#pragma once


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

    Point(){}

    void setPoint(string s){
        while(s.find(',') != -1)
            s[s.find(',')] = '.';
        x = stof(s.substr(0, s.find(';')));
        s = s.substr(s.find(';') + 1);
        y = stof(s.substr(0, s.find(';')));
        s = s.substr(s.find(';') + 1);
        type = s.substr(0, s.find(';'));
        s = s.substr(s.find(';') + 1);
        subtype = s.substr(0, s.find(';'));
        s = s.substr(s.find(';') + 1);
        name = s.substr(0, s.find(';'));
        s = s.substr(s.find(';') + 1);
        address = s.substr(0, s.find(';'));

        // return Point(x, y, type, subtype, name, address);
    }

};
