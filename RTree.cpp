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

void RTree::insert(Point point){
    if (!boundary.contains(point)) {
        return;
    }
    if (points.size() < capacity) {
        points.push_back(point);
        // cout << "pushed\n";
        return;
    }
    if (!divided) {
        subdivide();
    }
    if (northeast->boundary.contains(point)) {
        northeast->insert(point);
        return;
    }
    if (northwest->boundary.contains(point)) {
        northwest->insert(point);
        return;
    }
    if (southeast->boundary.contains(point)) {
        southeast->insert(point);
        return;
    }
    if (southwest->boundary.contains(point)) {
        southwest->insert(point);
        return;
    }
}

// bool RTree::insert(Point point){
//     if (!boundary.contains(point)) {
//         return false;
//     }
//     if (points.size() < capacity) {
//         points.push_back(point);
//         return true;
//     }
//     if (!divided) {
//         subdivide();
//     }
//
//     return (
//         northeast->insert(point) ||
//         northwest->insert(point) ||
//         southeast->insert(point) ||
//         southwest->insert(point)
//     );
// }

void RTree::print(){
    int n = 0;
    for (size_t i = 0; i < points.size(); i++) {
        cout << points[i].latitude << ", " << points[i].longitude << endl; n++;
    }
    if (divided) {
        print(northeast, n);
        print(northwest, n);
        print(southeast, n);
        print(southwest, n);
    }
    cout << n << endl;
}

void RTree::print(RTree *tree, int &n){
    for (size_t i = 0; i < tree->points.size(); i++) {
        cout << tree->points[i].latitude << ", " << tree->points[i].longitude << endl;
        n++;
    }
    if (tree->northeast) {
        cout << "northeast" << endl;
        print(tree->northeast, n);
    }
    if (tree->northwest) {
        cout << "northwest" << endl;
        print(tree->northwest, n);
    }
    if (tree->southeast) {
        cout << "southeast" << endl;
        print(tree->southeast, n);
    }
    if (tree->southwest) {
        cout << "southwest" << endl;
        print(tree->southwest, n);
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

        // for (size_t i = 0; i < 18; i++) {
        //     getline(infile, tmp);
        //     point.setPoint(tmp);
        //     insert(point);
        //     cout << tmp << endl;
        // }
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
