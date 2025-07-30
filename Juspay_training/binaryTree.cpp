#include<iostream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree{
    public:
    Node* root;
    
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front(); q.pop();
            if (!temp->left) {
                temp->left = newNode;
                break;
            } else q.push(temp->left);

            if (!temp->right) {
                temp->right = newNode;
                break;
            } else q.push(temp->right);
        }
    }


    void preorder(Node* temp){
        if(temp == nullptr){
            return;
        }
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void traverse(){
        preorder(root);
    }
};



int main()
{
    string inp;
    getline(cin, inp);

    stringstream ss(inp);

    BinaryTree bt;

    int val;
    while(ss >> val){
        bt.insert(val);
    }

    bt.traverse();
    return 0;
}