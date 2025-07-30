#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert elements using level-order traversal
void insert(Node*& root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = new Node(key);
            return;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = new Node(key);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Function for In-Order Traversal
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);  // Visit left subtree
    cout << root->data << " ";      // Print root
    inOrderTraversal(root->right); // Visit right subtree
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }

    cout << "In-Order Traversal: ";
    inOrderTraversal(root);

    return 0;
}
