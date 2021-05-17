#include "RTree.hpp"

RTree::RTree(Rectangle bound){
    boundary = bound;
    northeast = NULL;
    northwest = NULL;
    southeast = NULL;
    southwest = NULL;
    all = false;
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
    Rectangle ne((boundary.lat2 + boundary.lat1) / 2, (boundary.long2 + boundary.long1) / 2, boundary.lat2, boundary.long2);
    northeast = new RTree(ne);
    Rectangle nw(boundary.lat1, (boundary.long2 + boundary.long1) / 2, (boundary.lat2 + boundary.lat1) / 2, boundary.long2);
    northwest = new RTree(nw);
    Rectangle se((boundary.lat2 + boundary.lat1) / 2, boundary.long1, boundary.lat2, (boundary.long2 + boundary.long1) / 2);
    southeast = new RTree(se);
    Rectangle sw(boundary.lat1, boundary.long1, (boundary.lat2 + boundary.lat1) / 2, (boundary.long1 + boundary.long2) / 2);
    southwest = new RTree(sw);

    divided = true;
}

void RTree::insert(Point point){
    if (!boundary.contains(point)) {
        return;
    }

    if (types.size() == 5) all = true;
    if (types.size() < 5) {
        bool there = false;
        for (size_t i = 0; i < types.size(); i++) {
            if (types[i] == point.type) {
                there = true;
                break;
            }
        }
        if (!there) types.push_back(point.type);
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

bool RTree::makeTree(string filename){
    ifstream infile(filename);
    if (!infile) {
        cout << "Sorry, unable to open the file :(\n";
        return false;
    } else {
        string tmp;
        Point point;
        getline(infile, tmp);
        do {
            point.setPoint(tmp);
            insert(point);
            getline(infile, tmp);
        } while (!infile.eof() && tmp != "");
    }
    return true;
}

bool RTree::IsPointInCircle(double x, double y, Circle circle){
    return (sqrt((x - circle.x) * (x - circle.x) + (y - circle.y) *
           (y - circle.y)) < circle.radius);
}

bool IsPointInRectangle(double x, double y, Rectangle boundary){
    double latitude = y / 111.135,
           longitude = x / (111.321 * cos(latitude * M_PI / 180));

    return (latitude > boundary.lat1 || longitude > boundary.long1 ||
            latitude < boundary.lat2 || longitude < boundary.long2);
}


bool RTree::intersection(Rectangle boundary, Circle circle){
    return (IsPointInRectangle(circle.x - circle.radius, circle.y - circle.radius, boundary) ||
            IsPointInRectangle(circle.x + circle.radius, circle.y - circle.radius, boundary) ||
            IsPointInRectangle(circle.x - circle.radius, circle.y + circle.radius, boundary) ||
            IsPointInRectangle(circle.x + circle.radius, circle.y + circle.radius, boundary));
}

void RTree::findPoints(Point point, double radius, vector <Point> &result, string search_type){
    Circle circle(point, radius);
    for (size_t i = 0; i < points.size(); i++) {
        if (IsPointInCircle(points[i].x, points[i].y, circle) && search_type == points[i].type) {
            result.push_back(points[i]);
        }
    }
    if (divided) {
        if (intersection(northeast->boundary, circle) && northeast->types.size() == 5) {
            northeast->findPoints(point, radius, result, search_type);
        } else if (intersection(northeast->boundary, circle) && northeast->containsType(search_type)){
            northeast->findPoints(point, radius, result, search_type);
        }

        if (intersection(northwest->boundary, circle) && northwest->types.size() == 5) {
            northwest->findPoints(point, radius, result, search_type);
        } else if (intersection(northwest->boundary, circle) && northwest->containsType(search_type)){
            northwest->findPoints(point, radius, result, search_type);
        }

        if (intersection(southeast->boundary, circle) && southeast->types.size() == 5) {
            southeast->findPoints(point, radius, result, search_type);
        } else if (intersection(southeast->boundary, circle) && southeast->containsType(search_type)){
            southeast->findPoints(point, radius, result, search_type);
        }

        if (intersection(southwest->boundary, circle) && southwest->types.size() == 5) {
            southwest->findPoints(point, radius, result, search_type);
        } else if (intersection(southwest->boundary, circle) && southwest->containsType(search_type)){
            southwest->findPoints(point, radius, result, search_type);
        }

    }
}

bool RTree::containsType(string search_type){
    for (size_t i = 0; i < types.size(); i++) {
        if (types[i] == search_type) {
            return true;
        }
    }
    return false;
}
