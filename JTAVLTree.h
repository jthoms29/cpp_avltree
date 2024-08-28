template<typename T>
class JTAVLTree : public JTBinTree<T> {

public:
    /*
     * Constructs a JTAVLTree locally.
     * Calls JTBinTree's default constructor, since our instance variable is of a different type.
     * The JTBinTree parent class will have a nullptr node, while this one's AVL node is set
     * to the specified value
     * T element: The element to set as value for root node
     */
    JTAVLTree(T element) :head{createNode(element)}{}


    /*
     * Inserts specified value into AVL tree
     * T element: Element to insert into tree
     */
    void insert(T element) {
        insertRecurseHelper(element, (JTAVLNode<T>*) getHead());
    }


    /* Needed to copy this to this class since our AVLNode head needed to be passed to it. Otherwise,
     * JTBinTree's null node would be passed. JTBinTrees printTreeUtil still works in its own class
     */
    void printTree() {
        this->printTreeUtil(head, 0);

    }

    /*
     * Returns reference to new AVL node on the heap.
     * Overwrites JTBinNode's class
     * T val: Value to have in new node
     */
    JTAVLNode<T>* createNode(T val) {
        return JTAVLNode<T>::createJTAVLNode(val);
    }

    /*
     * Returns the head of the AVL tree
     * Overwrites JTBinNode's class
     */
    JTAVLNode<T>* getHead() {
        return head;
    }

private:
    
    JTAVLNode<T>* head; //head node. Sort of overwrites JTBinTree's head.

    /**
     * Seperate insertion function needed since this tree needs to rebalance itself
     * T val: Value to insert into tree
     * JTAVLNode<T>* node: Current node in tree
     */
    void insertRecurseHelper(T val, JTAVLNode<T>* node) {
        if (val > node->getElement()) {
            if (node->getRightRef() == nullptr) 
                node->setRightChild(createNode(val));

            else
                insertRecurseHelper(val, node->getRightRef());
        }

        else if (val < node->getElement()) {
            if (node->getLeftRef() == nullptr)
                node->setLeftChild(createNode(val));

            else
                insertRecurseHelper(val, node->getLeftRef());
        }
        node->setSubHeight(std::max(node->getLeftHeight(), node->getRightHeight()));
        restoreAVLProperty(node);
    }


    /*
     * Looks at imbalance of current node and restores AVL property if neccesarry
     * JTAVLNode<T>* node: The node to restore AVL property on
     */
    void restoreAVLProperty(JTAVLNode<T>* node) {
        int imbalance = signedImbalance(node);
        if (std::abs(imbalance) <= 1) return;

        if (imbalance == 2) {  //left Heavy
            if (signedImbalance(node->getLeftRef()) >= 0)  // LL imbalance
                rotateRight(node);
            else {                                         // LR imbalance
                rotateLeft(node->getLeftRef()); 
                rotateRight(node);
            }
        }

        else  { //right Heavy
            if (signedImbalance(node->getRightRef()) <= 0) //RR imbalance
                rotateLeft(node);
            else {                                        //RL imbalance
                rotateRight(node->getRightRef());
                rotateLeft(node);
            }
        }
    }

    /*
     * Returns the signed imbalance of the specified node
     * JTAVLNode<T>* node: Node to find signed imbalance of
     */
    int signedImbalance(JTAVLNode<T>* node) {
        return node->getLeftHeight() - node->getRightHeight();
    }


    /*
     * Performs a left rotation on the specified node
     * JTAVLNode<T>* node: Node to preform left rotation on
     */
    void rotateLeft(JTAVLNode<T>* node) {
        // creating new node to be left child
        JTAVLNode<T>* rep = createNode(node->getElement());
        rep->setLeftChild(node->getLeftRef());
        rep->setRightChild(node->getRightRef()->getLeftRef());
        rep->setSubHeight(std::max(rep->getLeftHeight(), rep->getRightHeight()));

        //making current node right child
        node->setElement(node->getRightRef()->getElement());
        node->setRightChild(node->getRightRef()->getRightRef());


        //setting left child to be replacement
        delete node->getLeftRef();
        node->setLeftChild(rep);
        node->setSubHeight(std::max(node->getLeftHeight(), node->getRightHeight()));
    }

    /*
     * Performs right rotation on specified node
     * JTAVLNode<T>* node: Node to perform right rotation on
     */
    void rotateRight(JTAVLNode<T>* node) {
        // creating new node to be right child
        JTAVLNode<T>* rep = createNode(node->getElement());
        rep->setRightChild(node->getRightRef());
        rep->setLeftChild(node->getLeftRef()->getRightRef());
        rep->setSubHeight(std::max(rep->getLeftHeight(), rep->getRightHeight()));

        //making current node left child
        node->setElement(node->getLeftRef()->getElement());
        node->setLeftChild(node->getLeftRef()->getLeftRef());

        //seting right child to be replacement
        delete node->getRightRef();
        node->setRightChild(rep);
        node->setSubHeight(std::max(node->getLeftHeight(), node->getRightHeight()));
    }


};
