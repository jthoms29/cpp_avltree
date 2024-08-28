template<typename T>
class JTAVLNode : public JTBinNode<T> {

public:

    /*
     * Statically returns pointer to heap allocated AVL Node
     * To avoid local instantiation
     * T element: Element of type T to add to node
     */
    static JTAVLNode* createJTAVLNode(T element) {
        return new JTAVLNode(element);
    }

    /*
     * Returns the height of the node's subtree
     */
    int getSubHeight() {
        return subtreeHeight;
    }

    /*
     * Sets the height of the node's subtree
     */
    void setSubHeight(int height) {
        subtreeHeight = height;
    }

    /*
     * Gets the height of the right subtree. Won't necessarily be the regular subtree height,
     * that's the max of left and right
     */
    int getRightHeight() {
        if (this->getRightRef() == nullptr) return 0;
        return getRightRef()->getSubHeight()+1;
    }

   /*
    * Gets the height of the left subtree
    */
    int getLeftHeight() {
        if (this->getLeftRef() == nullptr) return 0;
        return getLeftRef()->getSubHeight()+1;
    }

    /*
     * Casting class. Returns a reference to the left child
     */
    JTAVLNode<T>* getLeftRef() {
        return (JTAVLNode<T>*) JTBinNode<T>::getLeftRef();
    }

    /*
     * Casting class. Returns a reference to the right child
     */
    JTAVLNode<T>* getRightRef() {
        return (JTAVLNode<T>*) JTBinNode<T>::getRightRef();
    }

private:
    unsigned int subtreeHeight; //Height of the subtree in the AVL Tree

    /**
     * Private to stop from being locally instantiated. Constructs new JTAVLNode
     * using JTBinNode's constructor
     * T element: Element of type T to have in node
     */
    JTAVLNode(T element) : JTBinNode<T>({element}), subtreeHeight{0} {}
};


