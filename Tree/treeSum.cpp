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
    Node* root = nullptr;

    void insert() {
        int num;
        queue<Node*> q;
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

            vector<Node*> leafNodes;
            int size = q.size();
            bool hasValidLeaf = false; 

            for (int i = 0; i < size; i++) {
                Node* current = q.front();

                
                if ((current->left == nullptr && current->right == nullptr) || 
                    (current->left && current->left->data == -1 && 
                     current->right && current->right->data == -1)) {
                    leafNodes.push_back(current);
                }

                
                if (current->left == nullptr) {
                    current->left = new Node(num);
                    if (num != -1) {
                        q.push(current->left);
                        hasValidLeaf = true; 
                    }
                    break;
                }
                if (current->right == nullptr) {
                    current->right = new Node(num);
                    if (num != -1) {
                        q.push(current->right);
                        hasValidLeaf = true;
                    }
                    q.pop();
                    break;
                }
            }
            if (!hasValidLeaf) break;
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
