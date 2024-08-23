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
    /*
     * Constructs a new binary node. Left and right child are null to begin
     * with
     * T element: The element to add to the new node
     */
    JTBinNode(T element)
        :element{element}, leftChild{nullptr}, rightChild{nullptr} {}

    /*
     * Sets a pointer to a different node to be the left child of current node
     * JTBinNode* node: The node to make left child
     */
    void setLeftChild(JTBinNode* node) {
        leftChild = node;
    }

    // Not sure what general practice is, but having separate getter for
    // references seems useful
    /*
     * Returns a pointer to the left child
     */
    JTBinNode* getLeftRef() const {
        return leftChild;
    }

    /*
     * Returns the left child by value
     */
    JTBinNode getLeftChild() const {
        return *leftChild;
    }

    /*
     * Sets a pointer to a different node to be the right child of current node
     * JTBinNode* node: The node to make right child
     */
    void setRightChild(JTBinNode* node) {
        rightChild = node;
    }
   
    /*
     * Returns a pointer to the right child
     */
    JTBinNode* getRightRef() const {
        return rightChild;
    }

    /*
     * Returns the right child by value
     */
    JTBinNode getRightChild() {
        return *rightChild;
    }

    /*
     * Returns the element held by the node by value
     */
    T getElement() const {
        return element;
    }

    /*
     * Sets a new element to be the one held by node
     * T el: The element to add to the node
     */
    void setElement(T el) {
        element = el;
    }

    /*
     * Destructor. Recursively deletes children.
     */
    ~JTBinNode() {
        delete leftChild;
        delete rightChild;
    }

};
