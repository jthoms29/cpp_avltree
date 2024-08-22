//#include "JTBinNode.h" <- This is like defining it twice since this is also a header file.

// Another header only class
template<typename T>
class JTBinTree {
private:
    JTBinNode<T>* head;
    JTBinNode<T>* cur;     // The current node of cursor
    JTBinNode<T>* prev;    // Previous node of cursor
                           
    
public:
    JTBinTree(JTBinNode<T>* node)
    // cursor will be initialized to the before position (null, null)
        :head{node}, cur{nullptr}, prev{nullptr} {}


    bool search(T val) const {
        // do exception
        bool isIn = false;
        searchRecurseHelper(val, head, &isIn);
        return isIn;
         
    }

    void searchRecurseHelper(T val, const JTBinNode<T>* node, bool* found) const {
        if (node == nullptr)
            return;

        if (node->getElement() > val) {
            searchRecurseHelper(val, node->getLeftRef(), found);
        }

        if (node->getElement() < val)
            searchRecurseHelper(val, node->getRightRef(), found);

        else
            *found = true;
    }
    

};
