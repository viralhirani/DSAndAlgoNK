#include<iostream>
#include<initializer_list>
#include<memory>
#include<queue>
using namespace std;

//create a symple tree class
template<typename T>
struct Node {
    T data{};
    Node* left{nullptr};
    Node* right{nullptr};
public:
    Node() {}
    Node(T data_): data(data_) {}
};

template<typename T>
class MyTree
{
    Node<T>* _root{nullptr};

public:
    // by default create a empty tree;
    MyTree()
    {
        _root = new Node<T>();
    }
    MyTree(T data)
    {
        _root = new Node<T>(data);
    }
    //TODO Create a simple binary tree with initializer list.
    shared_ptr<Node<T>> insertNode(T data_)
    {
        // if root is nullptr build the fist node and return
        if (_root == nullptr) {
            _root = make_shared<Node<T>>(data_);
            return _root;
        }
        // otherwise do level order traversal untill we find an empty place
        //i.e. either let child or right child of some ode is pointing to NULL than add new node there.
        queue<Node<T>*> q;
        
        return _root;
    }
    Node<T>* createNode(T data_)
    {
        Node<T>* newNode = new Node<T>(data_);
        return newNode;
    }
    Node<T>* root() { return _root;}

    // Traversal:
    void inorder(Node<T>* temp)
    {
        if (temp == NULL)
            return;
    
        inorder(temp->left);
        cout << temp->data << ' ';
        inorder(temp->right);
    }

    void preorder(Node<T>* temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->data << ' ';
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(Node<T>* temp)
    {
        if (temp == nullptr)
            return;
        
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << ' ';
    }

};

int main()
{
    MyTree<int> myTree(1);

    //myTree.root() = myTree.createNode(1);
    myTree.root()->left = myTree.createNode(2);
    myTree.root()->right = myTree.createNode(3);
    myTree.root()->left->left = myTree.createNode(4);
    myTree.root()->left->right = myTree.createNode(5);
    myTree.root()->right->left = myTree.createNode(6);
    myTree.root()->right->right = myTree.createNode(7);


    //cout<<myTree.root()->left->left->data<<endl;

    cout<<"Inorder-------"<< endl;
    myTree.inorder(myTree.root());
    cout<<endl;
    cout<<"Preorder-------"<< endl;
    myTree.preorder(myTree.root());
    cout<<endl;
    cout<<"Postorder-------"<< endl;
    myTree.postorder(myTree.root());
    cout<<endl;
    return 0;
}