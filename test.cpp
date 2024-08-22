#include <iostream>
#include "JTBinNode.h"

using namespace::std;

int main(void) {
    JTBinNode test1 = 5;
    JTBinNode test2 = 4;
    JTBinNode test3 = 6;

    test1.setLeftChild(&test2);
    test1.setRightChild(&test3);

    

    cout << test1.getElement() << endl;
    cout << test1.getLeftChild().getElement() << endl;
    cout << test1.getRightChild().getElement() << endl;

}

