#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val =val;
        this->left =  nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node( val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int m){
    if(m == 0) return nullptr;
    Node* root = nullptr;
    for(int i=0;i<m;i++){
        root = insert(root, arr[i]);
    }
}



int main()
{
    int arr[] = {9,3,5,1,4,14,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildBST(arr, n);
    return 0;
}