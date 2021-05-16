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
    int capacity = 2;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;


    RTree(Rectangle bound);

    RTree(RTree *tree);

    void subdivide();

    // bool insert(Point point);

    void insert(Point point);

    void print();

    void print(RTree *tree, int &n);

    bool makeTree(string filename);

    vector<Point> findPoints(Point point, double radius);

    void findPoints(RTree *tree, Point point, double radius, vector <Point> &result);

    bool intersection(RTree *tree, Circle circle);

    bool IsPointInCircle(Point point, Circle circle);
};
