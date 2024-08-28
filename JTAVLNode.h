template<typename T>
class JTAVLNode : public JTBinNode<T> {
private:
    unsigned int subtreeHeight;
    JTAVLNode(T element) : JTBinNode<T>({element}), subtreeHeight{0} {}

public:

    static JTAVLNode* createJTAVLNode(T element) {
        return new JTAVLNode(element);
    }

    int getSubHeight() {
        return subtreeHeight;
    }

    void setSubHeight(int height) {
        subtreeHeight = height;
    }

    int getRightHeight() {
        if (this->getRightRef() == nullptr) return 0;
        return getRightRef()->getSubHeight()+1;
    }

    int getLeftHeight() {
        if (this->getLeftRef() == nullptr) return 0;
        return getLeftRef()->getSubHeight()+1;
    }

    JTAVLNode<T>* getLeftRef() {
        return (JTAVLNode<T>*) JTBinNode<T>::getLeftRef();
    }

    JTAVLNode<T>* getRightRef() {
        return (JTAVLNode<T>*) JTBinNode<T>::getRightRef();
    }

};


