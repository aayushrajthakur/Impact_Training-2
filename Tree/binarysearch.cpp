#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    // Node* root = nullptr;
    void Node* insert(Node* root,int input){
        if(root==nullptr){
            root=new Node(input);
            return root;
        }
        else if(input<=root.data){
            root.left=insert(root.left,input);
        }
        else{
            root.right=insert(root.right,input);
        }
        return root;
    }

    void insert() {
        int num;
        queue<Node*> q;
        Node* root=nullptr;
        int input;
        cin>>input;
        if(input!=-1){
            root=new Node(input);
        }
        int i=0;
        int input1;
        int input2;
        cin>>input1;
        cin>>input2;
        while (input1!=-1 && input2!=-1) {
            root=insert(root,input1);
            root=insert(root,input2);
            cin>>input1;
            cin>>input2;
        }
            
    }
    void postOrderTraversal(Node* node) {
        if (!node) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    void printPostOrder() {
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.insert();
    
    cout << "Post-order Traversal: ";
    bt.printPostOrder(); 

    return 0;
}
