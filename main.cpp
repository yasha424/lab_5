#include "RTree.hpp"
#include <ctime>
using namespace std;

int main(int argc, char const *argv[]) {
    Rectangle rec(0, 0, 5, 5);
    RTree tree(rec);
    for (size_t i = 0; i < 200; i++) {
        Point point(rand()%360, rand()%360, "type", "sub", "name", "address");
        tree.insert(point);
    }

    // RTree newtree(tree.northeast);
    // cout << tree.northeast->northeast << endl;
    // cout << newtree.northeast << endl;
}
