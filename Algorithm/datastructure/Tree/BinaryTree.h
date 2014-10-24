#ifdef __BINARY_TREE__
#undef __BINARY_TREE__

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data):data(data),left(NULL),right(NULL){}
};

class BinaryTree{
    Node* root;
    BinaryTree(Node* root):root(root){}
    BuildBySize(int size);
    int GetHeight();
};

class BinarySearchTree{
    Node* root;
    BinarySearchTree(Node* root):root(root){}
};
#endif __BINARY_TREE__


