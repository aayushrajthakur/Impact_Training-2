#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
class LinkedList{
    public:
    Node* head;
    Node* tail;


    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    Node* insert(int data){
        if(head == nullptr){
            head = new Node(data);
            tail = head;
            return tail;
        }
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        return head;

    }

    Node* removeNth_Node(int n) {
        if(head == nullptr){
            return nullptr;
        }
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* first = dummy;
        Node* second = dummy;

        for(int i=0; i<= n; ++i){
            first = first->next;
        }

        while(first != nullptr){
            first = first->next;
            second = second->next;
        }

        Node* todelete = second->next;
        second->next = second->next->next;
        delete(todelete);
        return dummy->next;
    }

    void print() {
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main()
{
    string inp;
    getline(cin, inp);
    
    LinkedList ll;

    stringstream ss(inp);

    int num;
    while(ss >> num){
        ll.insert(num);
    }

    cout<<"Enter the nth value to be delete : ";
    int n;
    cin>>n;
    ll.removeNth_Node(n);

    ll.print();

    return 0;
}