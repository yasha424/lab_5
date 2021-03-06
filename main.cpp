#include "RTree.hpp"
#include <ctime>
using namespace std;

void printPlaces(vector <Point> points);

int main(int argc, char const *argv[]) {
    if (argc != 6) {
        cout << "There should be 6 arguments!\n";
        return 0;
    }
    argv[1]="D:\\lab5\\cmake-build-debug\\CMakeFiles\\ukraine_poi.csv";
    Rectangle rec(0, 0, 90, 180);
    RTree tree(rec);
    string type = argv[5];
    double start = clock();
    if (tree.makeTree(argv[1])){
        double build_time = clock() - start;

        Point point(stod(argv[2]), stod(argv[3]));
        double radius = stod(argv[4]);

        start = clock();
        vector <Point> result;
        tree.findPoints(point, radius, result,type);
        double finding_time = clock() - start;

        cout << "Building time is: " << build_time / 1000000 << endl;
        cout << "Finding time is: " << finding_time / 1000000 << endl;
        printPlaces(result);
    }
}

void printPlaces(vector <Point> points){
    cout << "\nWe found next places in this area:\n";
    for (size_t i = 0; i < points.size(); i++) {
        cout << i + 1 << ") " << points[i].type << ", " << points[i].subtype;
        if (points[i].name != "") {
            cout << ", " << points[i].name;
        }
        if (points[i].address != "") {
            cout << ", " << points[i].address;
        }
        cout << ", with coordinates " << points[i].latitude << ", " << points[i].longitude;
        cout << ".\n";
    }
}
