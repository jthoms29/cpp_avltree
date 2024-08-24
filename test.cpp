#include <iostream>
#include "JTBinNode.h"
//#include "JTBinTree.h"

using namespace::std;

int main(void) {
    //JTBinNode tests ###################################################################
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

    //testing left child node methods
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

    //testing swapping left child
    JTBinNode<int>* newLeft = JTBinNode<int>::createJTBinNode(100);
    testNode->setLeftChild(newLeft);
    if (testNode->getLeftChild() == *leftTest)
        std::cout << "Left child swap issue\n";
    if (testNode->getLeftChild() != *newLeft)
        std::cout << "Left child swap issue\n";
    testNode->setLeftChild(leftTest);



    //testing right child node methods
    JTBinNode<int>* rightTest = JTBinNode<int>::createJTBinNode(6);
    testNode->setRightChild(rightTest);

    try {
        if (testNode->getRightChild() != *rightTest)
            std::cout << "getRightChild\n";
    }
    catch (int e) {
        std::cout << "Threw exception when checking right child of node\n";
    }

    if (testNode->getRightRef() != rightTest)
        std::cout << "getRightRef\n";


    //testing swapping right child
    JTBinNode<int>* newRight = JTBinNode<int>::createJTBinNode(101);
    testNode->setRightChild(newRight);
    if (testNode->getRightChild() == *rightTest)
        std::cout << "Right child swap issue\n";
    if (testNode->getRightChild() != *newRight)
        std::cout << "Right child swap issue\n";
    testNode->setRightChild(rightTest);

    //setElement
    testNode->setElement(99);
    if (testNode->getElement() != 99)
        std::cout << "setElement\n";

    testNode->setElement(5);


    //Testing comparison operator
    //Making different node with same values
    JTBinNode<int>* clone = JTBinNode<int>::createJTBinNode(5);
    if (*testNode == *clone)
        std::cout << "Clone with no children shouldn't == testNode\n";

    JTBinNode<int>* lClone = JTBinNode<int>::createJTBinNode(4);
    clone->setLeftChild(lClone);
    if (*testNode == *clone)
        std::cout << "Clone with one child shouldn't == testNode\n";

    JTBinNode<int>* rClone = JTBinNode<int>::createJTBinNode(6);
    clone->setRightChild(rClone);
    if (*testNode != *clone)
        std::cout << "testNode should == clone\n";

    
    //Testing JTBinTree #############################################################


}

