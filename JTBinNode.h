//template classes need to be written entirely in the .h files as far as I
//understand

Template<typename T>
class JTBinNode {
private:
    T* element;
    JTNode* leftChild;
    JTNode* rightChild;

public:
    JTBinNode(T* element)
        :element{element}, leftChild{nullptr}, rightChild{nullptr} {}

    void setLeftChild(T* element) {
        rightChild = element
    }

    T getLeftChild() {
        return *rightChild;
    }

    void set




}
