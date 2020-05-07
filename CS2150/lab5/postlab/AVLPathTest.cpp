// Boris Topalov, bnt4yb, 2/26/2020
// Filename: AVLPathTest.cpp
// Description: main method for testing our AVL Tree
#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);
        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
    // avl.printTree();
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}
