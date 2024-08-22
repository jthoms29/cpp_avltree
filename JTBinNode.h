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

    // Not sure what general practice is, but having separate getter for
    // references seems useful
    const JTBinNode* getLeftRef() const {
        return leftChild;
    }

    JTBinNode getLeftChild() const {
        return *leftChild;
    }

    void setRightChild(JTBinNode* node) {
        rightChild = node;
    }
    
    const JTBinNode* getRightRef() const {
        return rightChild;
    }

    JTBinNode getRightChild() {
        return *rightChild;
    }

    T getElement() const {
        return element;
    }

};
