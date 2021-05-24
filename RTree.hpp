#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "set"
#include "Rectangle.hpp"
// #include "Point.hpp"
using namespace std;

class RTree{
public:
    Rectangle boundary;
    set<string> types;
    int capacity = 4;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;

    RTree(Rectangle bound);

    RTree(RTree *tree);

    void subdivide();

    void insert(Point point);

    void print();

    void print(RTree *tree, int &n);

    bool makeTree(string filename);

    void findPoints(Point point, double radius, vector <Point> &result,string type="");

    bool intersection(Rectangle boundary, Circle circle);

    bool IsPointInCircle(double x, double y, Circle circle);
};
