#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right =  nullptr;
    }
};




Node* createTree(int data, Node* node){
    if(node == nullptr){
        return new Node(data);
    }else if(data < node->data){
        node->left = createTree(data, node->left);
    }else if(data > node->data){
        node->right = createTree(data, node->right);
    }
    return node;
}
Node* createBst(int arr[], int n){
    Node* root =  nullptr;
    for(int i=0;i<n;i++){
        root = createTree(arr[i], root);
    }
    return root;
}

void preorder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int m;
    cin>>m;

    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    Node* root = createBst(arr, m);
    cout<<"Preorder Traversal : ";
    preorder(root);
    cout<<"\nInorder Traversal : ";
    inorder(root);


    return 0;
}