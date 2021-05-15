#include "RTree.hpp"
#include <ctime>
using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 5) {
        cout << "There should be 5 arguments!\n";
        return 0;
    }
    Rectangle rec(0, 0, 7000, 7000);
    RTree tree(rec);

    tree.makeTree(argv[1]);
    Point point(stod(argv[2]), stod(argv[3]));
    double radius = stod(argv[4]) * 10000;

    vector <Point> result = tree.findPoints(point, radius);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i].latitude << ", " << result[i].longitude << ", " << result[i].subtype <<
             ", " << result[i].name << ", " << result[i].address << endl;
    }
    // tree.print();
}
