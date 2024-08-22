//template classes need to be written entirely in the .h files as far as I
//understand

template<typename T>
class JTBinNode {
private:
    /* It's expected that the element will just be a primitive type.
       May constrain type somehow later */
    T element;
    JTBinNode* leftChild;
    JTBinNode* rightChild;

public:
    JTBinNode(T element)
        :element{element}, leftChild{nullptr}, rightChild{nullptr} {}

    void setLeftChild(JTBinNode* node) {
        leftChild = node;
    }

    // Assume returning child shouldn't be a pointer
    JTBinNode getLeftChild() {
        return *leftChild;
    }

    void setRightChild(JTBinNode* node) {
        rightChild = node;
    }
    
    JTBinNode getRightChild() {
        return *rightChild;
    }

    T getElement() {
        return element;
    }

};
