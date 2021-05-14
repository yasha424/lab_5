#include "RTree.hpp"

RTree::RTree(string filename){
    ifstream infile(filename);
    string tmp;
    if (infile) {
        int row = 0;
        while (!infile.eof()) {
            getline(infile, tmp);
            Point point.make_point(tmp);
        }
    }
}
