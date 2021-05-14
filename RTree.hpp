#pragma once
#include <iostream>
#include <fstream>
#include "Point.hpp"
using namespace std;

struct Node{
    Point *data;
    Node *left, *right;
};

class RTree{
    Node *root;

    void addPoint(Node *node, Point point);

public:
    RTree(string);
    void addPoint(Point);
};
