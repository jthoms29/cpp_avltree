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



    /*
     * Constructs a new binary node. Left and right child are null to begin
     * with
     * T element: The element to add to the new node
     */
    JTBinNode(T element)
        :element{element}, leftChild{nullptr}, rightChild{nullptr} {}
public:

    /**
     * Static allocation causes issues when constructor is called. This, with the
     * instructor being private, ensures this class can never be statically allocated
     * T element: The element to add to the new node.
     */
    static JTBinNode* createJTBinNode(T element) {
        return new JTBinNode(element);
    }


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
        if (leftChild == nullptr)
            throw -1;
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
    JTBinNode getRightChild() const {
        if (rightChild == nullptr)
            throw -1;
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

template<typename T>
bool operator==(const JTBinNode<T>& n1, const JTBinNode<T>& n2) {
    bool check = true;
    if (n1.getElement() != n2.getElement()) check = false;
//    if (n1.getLeftChild().getElement() != n2.getLeftChild().getElement()) check = false;
 //   if (n1.getRightChild().getElement() != n2.getRightChild().getElement()) check = false;
    return check;
}

template<typename T>
bool operator!=(const JTBinNode<T>& n1, const JTBinNode<T>& n2) {
    return !(n1==n2);
}
// need to define operators
