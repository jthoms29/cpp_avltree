template<typename T>
class JTAVLNode : public JTBinNode {
public:

    JTAVLNode(T element) :JTBinNode(element), subtreeHeight{0} {}


private:
    unsigned int subtreeHeight;
}
