//#include<iostream>
//using namespace::std;
#include <initializer_list>
//#include "JTBinNode.h" <- This is like defining it twice since this is also a header file.

#define PRINT_PAD 10 //for printTree()
                    
// Another header only class
template<typename T>
class JTBinTree {
public:
    /*
     * Constructs new JTBinTree using element of type T as data element in root node
     * T element: Data of type T
     */
    JTBinTree(T element)
    // cursor will be initialized to the before position (null, null)
        :head{createNode(element)}, cur{nullptr}, prev{nullptr} {}


    /*
     * Initializer list constructor. T elements will be added to tree in order of list
     */
    JTBinTree(std::initializer_list<T> initList) {
        head = createNode(initList.begin()[0]);
        
        for (int i = 1; i < initList.size(); i++)
            insert(initList.begin()[i]);

    }


    /*
     * Searches binary tree for specified value. Returns true if in, false otherwise
     * T val: The value to be searched for
     */
    bool search(T val) const {
        // do exception
        bool isIn = false;
        searchRecurseHelper(val, head, isIn);
        return isIn; 
    }


    /*
     * Inserts new value into tree. Uses standard BST insertion alorithm
     * T val: Value to add node of into tree
     */
    void insert(T val) {
        if (search(val))
            throw -1;
        insertRecurseHelper(val, head);    
    }
    


    /* Test function, stolen from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ */
    void printTree() {
        printTreeUtil(head, 0);

    }

    /*
     * Deletes node with specified value from tree
     * T val: Value to delete from tree
     */
    void deleteNode(T val) {
        deleteNodeRecurseHelper(val, head);
    }

    JTBinTree() :head{nullptr} {}
    /*
     * Destructor. Deletes head node, which will in turn recursively delete entire tree.
     */
    ~JTBinTree() {
        delete head;
    }

private:
    JTBinNode<T>* head;
    JTBinNode<T>* cur;     // The current node of cursor
    JTBinNode<T>* prev;    // Previous node of cursor
                           

    /*
     * Recursively moves through tree looking for specified value. The found pointer is returned in the actual
     * search function
     * T val: Value of type T to find in tree
     * JTBinNode<T>* node: A pointer to the current node
     * bool* found: Indicates whether value has been found or not
     */
    void searchRecurseHelper(T val, JTBinNode<T>* node, bool& found) const {
        if (node == nullptr)
            return;

        if (node->getElement() > val) {
            searchRecurseHelper(val, node->getLeftRef(), found);
        }

        if (node->getElement() < val)
            searchRecurseHelper(val, node->getRightRef(), found);

        if (node->getElement() == val)
            found = true;
    }


    /*
     * Recursively moves through tree looking for place to put new value. Uses standard bst insertion
     * algorithm
     * T val: Value of type T to add a node with to tree
     * JTBinNode<T>* node: Current node in tree
     */
    void insertRecurseHelper(T val, JTBinNode<T>* node) {
        if (val > node->getElement()) {
            if (node->getRightRef() == nullptr) 
                node->setRightChild(createNode(val));

            else
                insertRecurseHelper(val, node->getRightRef());
        }

        if (val < node->getElement()) {
            if (node->getLeftRef() == nullptr)
                node->setLeftChild(createNode(val));

            else
                insertRecurseHelper(val, node->getLeftRef());
        }
    }

    /*
     * Helper function for node deletion. Handles all three cases for BST node deletion.
     * T val: Value to delete node of from tree
     * JTBinNode<T>* node: Current node in tree
     */
    bool deleteNodeRecurseHelper(T val, JTBinNode<T>* node) {
        if (node == nullptr)
            return false;

        if (node->getElement() > val) {
            if (deleteNodeRecurseHelper(val, node->getLeftRef()))
                node->setLeftChild(nullptr);
        }

        else if (node->getElement() < val) {
            if (deleteNodeRecurseHelper(val, node->getRightRef()))
                node->setRightChild(nullptr);
        }

        else if (node->getElement() == val) {
            //has two children
            if (node->getLeftRef() != nullptr && node->getRightRef() != nullptr) {
                T el = inOrderSuccessor(node);
                deleteNodeRecurseHelper(el, node);
                node->setElement(el);
            }

            // is leaf node
            else if (node->getLeftRef() == nullptr && node->getRightRef() == nullptr) {
                delete node;
                return true;
            }

            //has one child, it is grafted in place of current node
            else {
                JTBinNode<T>* child = node->getLeftRef();
                //only one will be null, so we just have to check one
                if (node->getRightRef() != nullptr)
                    child = node->getRightRef();

                node->setElement(child->getElement());
                node->setLeftChild(child->getLeftRef());
                node->setRightChild(child->getRightRef());

                delete(child);
            }
        }
        return false;
    }


    /*
     * Helper function for node deletion in the case that a node deletion has two
     * children. Finds the inorder successor of specified node.
     * JTBinNode<T>* node: Node to find inorder successor of
     */
    T inOrderSuccessor(JTBinNode<T>* node) {
        //finding the smallest element in the right hand subtree
        JTBinNode<T>* walker = node;
        walker = walker->getRightRef();

        while(walker->getLeftRef() != nullptr)
            walker = walker->getLeftRef();

        return walker->getElement();
    }

    /*
     * Utility function. Dynamically allocates new node with specified value
     * T val: Value to add to new node
     */
    JTBinNode<T>* createNode(T val) {
        return JTBinNode<T>::createJTBinNode(val);
    }

protected:
    /*
     * Returns head of tree for subclasses
     */
    JTBinNode<T>* getHead() {
        return head;
    }

    /*
     * Utility function used for printing tree. Not written by me
     */
    void printTreeUtil(JTBinNode<T>* root, int space) {
        
        if (root == nullptr)
            return;

        //increase dist between levels
        space += PRINT_PAD;

        //process right child first
        printTreeUtil(root->getRightRef(), space);

        //print current node after space count
        std::cout << std::endl;
        for (int i = PRINT_PAD; i < space; i++)
            std::cout << " ";
        std::cout << root->getElement() << "\n";

        printTreeUtil(root->getLeftRef(), space);

    }
};
