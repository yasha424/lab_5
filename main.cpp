#include "RTree.hpp"

int main(int argc, char const *argv[]) {
    Rectangle rec(0, 0, 5, 5);
    RTree tree(rec);
    Point point(5, 5, "type", "sub", "name", "address");
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);
    tree.insert(point);

    RTree newtree(tree.northeast);
    cout << tree.northeast->northeast << endl;
    cout << newtree.northeast << endl;
}
