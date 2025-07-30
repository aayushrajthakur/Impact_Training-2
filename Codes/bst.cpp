#include<iostream>
using namespace std;

class Node{
    public:

    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right= nullptr;
    }
};

class Tree{
    public:
    Node* root = nullptr;

    Tree() {
        root = nullptr;
    }
    Node* insert(Node* node, int val){
        if(node ==  nullptr){
            return new Node(val);
        }else if(val < node->val){
            node->left = insert(node->left, val);
        }else if(val > node->val){
            node->right = insert(node->right, val);
        }
        return node;
    }
    void insert(int val){
        root = insert(root,val);
    }
    void inorder(Node* node){
        if(node == nullptr){
            return;
        }
        inorder(node->left);
        cout<< node->val << " ";
        inorder(node->right);
    }
    void displayInorder(){
        cout<<"Inorder Traversal  : ";
        inorder(root);
        cout<<endl;
    }

    void preorder(Node* node){
        if(node == nullptr){
            return;
        }
        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    void displayPreorder() {
        cout<<"Preorder Traversal : ";
        preorder(root);
        cout<<endl;
    }
    void postorder(Node* node){
        if(node == nullptr){
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout<< node->val << " ";
    }
    void displayPostorder(){
        cout<<"Inorder Traversal  : ";
        postorder(root);
        cout<<endl;
    }
    

};

int main() {
    Tree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();
}