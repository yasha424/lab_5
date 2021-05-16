#include "RTree.hpp"
#include <ctime>
using namespace std;


int main(int argc, char const *argv[]) {
    if (argc != 5) {
        cout << "There should be 5 arguments!\n";
        return 0;
    }
    Rectangle rec(0, 0, 90, 90);
    RTree tree(rec);

    double start = clock();
    if (tree.makeTree(argv[1])){
        double build_time = clock() - start;

        Point point(stod(argv[2]), stod(argv[3]));
        double radius = stod(argv[4]);

        start = clock();
        // vector <Point> result = tree.findPoints(point, radius);
        double finding_time = clock() - start;

        // for (size_t i = 0; i < result.size(); i++) {
        //     cout << result[i].latitude << ", " << result[i].longitude << ", " << result[i].subtype <<
        //          ", " << result[i].name << ", " << result[i].address << endl;
        // }
        // cout << "Build time is: " << build_time / 1000000 << endl;
        // cout << "Finding time is: " << finding_time / 1000000 << endl;
        tree.print();
    }
}
