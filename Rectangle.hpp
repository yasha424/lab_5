#include <iostream>
#include <string>
#include <vector>
#include "point.hpp"
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
        // width = w;
        // height = h;
    }
};

class RTree{
public:
    Rectangle boundary;
    int capacity = 10;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;

    RTree(Rectangle rect){
        boundary = rect;
        northeast = NULL;
        northwest = NULL;
        southeast = NULL;
        southwest = NULL;
    }

    RTree(Rectangle bound, int n){
        boundary = bound;
        capacity = n;
        northeast = NULL;
        northwest = NULL;
        southeast = NULL;
        southwest = NULL;
    }

    void subdivide(){
        Rectangle ne(boundary.x2/2, boundary.y2/2, boundary.x2, boundary.y2);
        northeast = new RTree(ne);
        Rectangle nw(boundary.x1, boundary.y2/2, boundary.x2/2, boundary.y2);
        northwest = new RTree(nw);
        Rectangle se(boundary.x2/2, boundary.y1, boundary.x2, boundary.y2/2);
        southeast = new RTree(se);
        Rectangle sw(boundary.x1, boundary.y1, boundary.x2/2, boundary.y2/2);
        southwest = new RTree(sw);

        divided = true;
    }

    void insert(Point point){
        if (points.size() < capacity) {
            points.push_back(point);
        } else{
            subdivide();
        }
    }
};
