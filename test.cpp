#include <iostream>
#include "JTBinNode.h"
#include "JTBinTree.h"

using namespace::std;

int main(void) {

    cout << "Intertion test: " << endl;
    JTBinTree<int> tree(10);

    tree.insert(12);
    tree.insert(5);
    tree.insert(4);
    tree.insert(20);
    tree.insert(8);
    tree.insert(7);
    tree.insert(15);
    tree.insert(13);


    if (tree.search(5))
        cout << "yep\n";

    if (tree.search(9999))
        cout << "nope\n";

    tree.printTree();

    cout << "\n\n\n\n\n\n\n\n\nDeletionTest: " << endl;

    JTBinNode test2 = 50;
    JTBinTree tree2(50);

    tree2.insert(30);
    tree2.insert(70);
    tree2.insert(60);
    tree2.insert(80);
    tree2.insert(20);
    tree2.insert(40);

    tree2.printTree();
    
    tree2.deleteNode(20);
    tree2.deleteNode(30);
    tree2.deleteNode(50);

    cout << "$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n" << endl;
    tree2.printTree();
    
    cout << "\n\n\n\n";

    JTBinTree list({10,12,5,4,20,8,7,15,13});
    list.printTree();

}

