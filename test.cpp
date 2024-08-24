#include <iostream>
#include "JTBinNode.h"
//#include "JTBinTree.h"

using namespace::std;

int main(void) {
    //JTBinNode tests
    //getElement
    JTBinNode<int>* testNode = JTBinNode<int>::createJTBinNode(5);
    if (testNode->getElement() != 5)
        std::cout << "getElement() doesn't work correctly\n";

    //setting/getting children
    try {
        testNode->getLeftChild();
        std::cout << "Getting nullptr left child should throw except\n";
    }
    catch (int e) {}
    
    try {
        testNode->getRightChild();
        std::cout << "Getting nullptr right child should throw except\n";
    }
    catch (int e) {}

    if (testNode->getLeftRef() != nullptr)
        std::cout << "getLeftRef while nullptr\n";

    if (testNode->getRightRef() != nullptr)
        std::cout << "getRightRef while nullptr\n";

    JTBinNode<int>* leftTest = JTBinNode<int>::createJTBinNode(4);
    testNode->setLeftChild(leftTest);

    try {
        if (testNode->getLeftChild() != *leftTest)
            std::cout << "getLeftChild\n";
    }
    catch (int e) {
        std::cout << "Threw exception when checking left child of node\n";
    }
    
    if (testNode->getLeftRef() != leftTest)
        std::cout << "getLeftRef\n";

}

