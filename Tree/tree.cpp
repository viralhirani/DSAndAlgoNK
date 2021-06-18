#include<iostream>
#include<initializer_list>
#include<memory>
#include<stack>
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
/*
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
    */
    Node<T>* createNode(T data_)
    {
        Node<T>* newNode = new Node<T>(data_);
        return newNode;
    }
    Node<T>* root() { return _root;}

    // Traversal:

    void preorder(Node<T>* temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->data << ' ';
        preorder(temp->left);
        preorder(temp->right);
    }
    // Iterative preorder
    void preorderIterative()
    {
        //check the root. if Root null print empty and return
        // check root left and right. if they both are null print root and return.
        // add right and left to stack if they are non-null
        // every iterator get the stack top, print and add right and left

        if(_root == nullptr) {
            cout<< "The tree is empty"<< endl; 
            return;
        }
        stack<Node<T>*> s;
        Node<T>* temp = _root;
        while(1) { // this will broken when we empty the stack.
            while(temp) {
                cout<< temp->data << " "; // process the current node.
                s.push(temp); // add the current to stack so we can revisit it to visit right side of tree.
                temp = temp->left; // travers to left tree to process.
            }

            if (s.empty()) {
                break; // break if stack is empty so we dont have any more parent nodes to process
            }
            // take font fo the stack to process that parent.
            // process the right side of sub tree.
            temp = s.top()->right;
            s.pop();
           // temp = temp->right; 
        }

    }
    void inorder(Node<T>* temp)
    {
        if (temp == NULL)
            return;
    
        inorder(temp->left);
        cout << temp->data << ' ';
        inorder(temp->right);
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
    cout<<"Preorder Iterative-------"<< endl;
    myTree.preorderIterative();
    cout<<endl;
    cout<<"Postorder-------"<< endl;
    myTree.postorder(myTree.root());
    cout<<endl;

    return 0;
}