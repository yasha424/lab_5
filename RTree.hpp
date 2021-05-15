#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Rectangle.hpp"
#include "Point.hpp"
using namespace std;

class RTree{
public:
    Rectangle boundary;
    int capacity = 16;
    RTree *northeast, *northwest, *southeast, *southwest;
    vector <Point> points;
    bool divided = false;

    RTree(Rectangle bound);

    RTree(RTree *tree);

    void subdivide();

    bool insert(Point point);

    void print();

    void print(RTree *tree);

    void makeTree(string filename);
};
