template<typename T>
class JTAVLTree : public JTBinTree<T> {

private:
    JTAVLNode<T>* head;

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

    int signedImbalance(JTAVLNode<T>* node) {
        return node->getLeftHeight() - node->getRightHeight();
    }


    void rotateLeft(JTAVLNode<T>* node) {
        // creating new node to be left child
        JTAVLNode<T>* rep = createNode(node->getElement());
        rep->setLeftChild(node->getLeftRef());
        rep->setRightChild(node->getRightRef()->getLeftRef());
        rep->setSubHeight(std::max(rep->getLeftHeight(), rep->getRightHeight()));

        //making current node right child
        node->setElement(node->getRightRef()->getElement());
        node->setRightChild(node->getRightRef()->getRightRef());


        //seting left child to be replacement
        delete node->getLeftRef();
        node->setLeftChild(rep);
        node->setSubHeight(std::max(node->getLeftHeight(), node->getRightHeight()));
    }

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

    JTAVLNode<T>* createNode(T val) {
        return JTAVLNode<T>::createJTAVLNode(val);
    }

    JTAVLNode<T>* getHead() {
        return head;
    }

public:
    JTAVLTree(T element) :head{createNode(element)}{}
   void insert(T element) {
        insertRecurseHelper(element, (JTAVLNode<T>*) this->getHead());
    }


    /* Test function, stolen from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ */
    void printTree() {
        this->printTreeUtil(head, 0);

    }
};
