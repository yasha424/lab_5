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
    bool contains(Point a){
        return a.x< x2 && a.y<y2 && a.x>x1 &&a.y > y1; 
    }

};

class RTree{
public:
    Rectangle boundary;
    int capacity = 10;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;

    RTree(Rectangle bound){
        boundary = bound;
        northeast = NULL;
        northwest = NULL;
        southeast = NULL;
        southwest = NULL;
    }

    RTree(RTree *tree){ // copying
        boundary = tree->boundary;
        if (tree->divided) {
            northeast = tree->northeast;
            northwest = tree->northwest;
            southeast = tree->southeast;
            southwest = tree->southwest;
        } else {
            northeast = NULL;
            northwest = NULL;
            southeast = NULL;
            southwest = NULL;
        }
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
    
    bool insert(Point point){
        if (boundary.contains(point)) {
            return false;
        }
        if (points.size() < capacity) {
            points.push_back(point);
        }
        if (!divided) {
            subdivide();
        }

        return (
            northeast->insert(point) ||
            northwest->insert(point) ||
            southeast->insert(point) ||
            southwest->insert(point)
        );
  }
};