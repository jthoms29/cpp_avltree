
class JTAVLTree : public JTBinTree {
public:
    JTAVLTree(T element) :JTAVLTree(element) {}

    void insert(T element) {
        insertUtil(element, head);
    }

private:
    void insertUtil(T val, JTAVLNode* node) {
        if (val > node->getElement()) {
            if (node->getRightRef() == nullptr) 
                node->setRightChild(createNode(val));

            else
                insertRecurseHelper(val, node->getRightRef());
                restoreAVLProperty(node);
        }

        if (val < node->getElement()) {
            if (node->getLeftRef() == nullptr)
                node->setLeftChild(createNode(val));

            else
                insertRecurseHelper(val, node->getLeftRef());
                restoreAVLProperty(node);
        }

    void restoreAVLProperty(JTAVLNode* node) {
        int subHeight = getMaxSubHeight(JTAVLNode->getLeftRef(), JTAVLNode->getRightRef());
        if (subHeight < 1) return;



    }

    void rotateLeft(JTAVLNode* node) {
    }

    void rotateRight(JTAVLNode* node) {
    }

}
