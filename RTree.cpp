#include "RTree.hpp"

RTree::RTree(Rectangle bound){
    boundary = bound;
    northeast = NULL;
    northwest = NULL;
    southeast = NULL;
    southwest = NULL;
}

RTree::RTree(RTree *tree){ // copying
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

void RTree::subdivide(){
    Rectangle ne((boundary.x2 + boundary.x1) / 2, (boundary.y2 + boundary.y1) / 2, boundary.x2, boundary.y2);
    northeast = new RTree(ne);
    Rectangle nw(boundary.x1, (boundary.y2 + boundary.y1) / 2, (boundary.x2 + boundary.x1) / 2, boundary.y2);
    northwest = new RTree(nw);
    Rectangle se((boundary.x2 + boundary.x1) / 2, boundary.y1, boundary.x2, boundary.y2/2);
    southeast = new RTree(se);
    Rectangle sw(boundary.x1, boundary.y1, (boundary.x2 + boundary.x1) / 2, (boundary.y1 + boundary.y2) / 2);
    southwest = new RTree(sw);

    divided = true;
}

bool RTree::insert(Point point){
    if (!boundary.contains(point)) {
        return false;
    }
    if (points.size() < capacity) {
        points.push_back(point);
        return true;
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

void RTree::print(){
    print(northeast);
    print(northwest);
    print(southeast);
    print(southwest);
}

void RTree::print(RTree *tree){
    for (size_t i = 0; i < tree->points.size(); i++) {
        cout << tree->points[i].x << ", " << tree->points[i].y << endl;
    }
    if (tree->northeast) {
        print(tree->northeast);
    }
    if (tree->northwest) {
        print(tree->northwest);
    }
    if (tree->southeast) {
        print(tree->southeast);
    }
    if (tree->southwest) {
        print(tree->southwest);
    }
}

void RTree::makeTree(string filename){
    ifstream infile(filename);
    if (!infile) {
        cout << "Sorry, unable to open the file :(\n";
        return;
    } else {
        string tmp;
        Point point;
        int i = 0;
        getline(infile, tmp);
        do {
            point.setPoint(tmp);
            insert(point);
            getline(infile, tmp);
        } while (!infile.eof() && tmp != "");
    }
}

// да, да, названия придумывать я не умею....
bool RTree::IsPointInCircle(Point point, Circle circle){
    return (sqrt((point.x - circle.x) * (point.x - circle.x) + (point.y - circle.y) * (point.y - circle.y))) <= circle.radius;
}

bool RTree::intersection(RTree *tree, Circle circle){
    return (((tree->boundary.x1 - circle.x) * (tree->boundary.x1 - circle.x)) + ((tree->boundary.y1 - circle.y) * (tree->boundary.y1 - circle.y))) <= circle.radius ||
           (((tree->boundary.x2 - circle.x) * (tree->boundary.x2 - circle.x)) + ((tree->boundary.y2 - circle.y) * (tree->boundary.y2 - circle.y))) <= circle.radius;
}

void RTree::findPoints(RTree *tree, Point point, double radius, vector <Point> &result){
    Circle circle(point, radius);
    for (size_t i = 0; i < points.size(); i++) {
        if (IsPointInCircle(points[i], circle)) {
            result.push_back(points[i]);
        }
    }
    if (intersection(northeast, circle)) {
        findPoints(tree->northeast, point, radius, result);
    }
    if (intersection(northwest, circle)) {
        findPoints(tree->northwest, point, radius, result);
    }
    if (intersection(southeast, circle)) {
        findPoints(tree->southeast, point, radius, result);
    }
    if (intersection(southwest, circle)) {
        findPoints(tree->southwest, point, radius, result);
    }

}

vector<Point> RTree::findPoints(Point point, double radius){
    vector<Point> result;
    Circle circle(point, radius);
    for (size_t i = 0; i < points.size(); i++) {
        if (IsPointInCircle(points[i], circle)) {
            result.push_back(points[i]);
        }
    }
    if (intersection(northeast, circle)) {
        findPoints(northeast, point, radius, result);
    }
    if (intersection(northwest, circle)) {
        findPoints(northwest, point, radius, result);
    }
    if (intersection(southeast, circle)) {
        findPoints(southeast, point, radius, result);
    }
    if (intersection(southwest, circle)) {
        findPoints(southwest, point, radius, result);
    }
    return result;
}
