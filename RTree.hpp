#pragma once

#include <iostream>
#include "Rectangle.hpp"
using namespace std;

class RTree{
public:
    Rectangle boundary;
    int capacity = 10;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;

    RTree(Rectangle bound);

    RTree(RTree *tree);

    void subdivide();

    bool insert(Point point);

    void print();

    void print(RTree *tree);
};
