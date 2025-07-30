#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        Node* left = nullptr;
        Node* right = nullptr;
    }
};


Node* createNode(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root->left =  createNode(arr, start, mid-1);
    root->right = createNode(arr, mid+1,end);

    return root;
}

void preorder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    
    if(root == NULL) return;
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

    Node* root = createNode(arr, 0, m-1);
    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<"\nPreorder Traversal : ";
    preorder(root);
    cout<<endl;
    return 0;
}