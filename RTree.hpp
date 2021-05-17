#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Rectangle.hpp"
// #include "Point.hpp"
using namespace std;

class RTree{
public:
    Rectangle boundary;
    int capacity = 10;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;
    bool all = false;
    vector <string> types;

    RTree(Rectangle bound);

    RTree(RTree *tree);

    void subdivide();

    void insert(Point point);

    void print();

    void print(RTree *tree, int &n);

    bool makeTree(string filename);

    void findPoints(Point point, double radius, vector <Point> &result, string search_type);

    bool intersection(Rectangle boundary, Circle circle);

    bool IsPointInCircle(double x, double y, Circle circle);

    bool containsType(string search_type);
};
