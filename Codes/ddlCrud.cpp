#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr; 
    }
};

Node* head = nullptr;
Node* tail = nullptr;
void insertfront(int a){
    Node* newnode = new Node(a);
    if(head == nullptr){
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insertend(int a) {
    Node* newnode = new Node(a);
    if(head == nullptr){
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insertpos(int a, int pos) {
    
    Node* newnode = new Node(a);
    if(pos == 1) {
        insertfront(a);
    } else{
        Node* temp = head;
        int count = 1;
        while(count < pos-1 && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if(temp != nullptr) {
            newnode->next = temp->next;
            newnode->prev = temp;
            if(temp->next != nullptr){
                temp->next->prev = newnode;
            }
            temp->next = newnode;
            if(newnode->next == nullptr){
                tail = newnode;
            }
        } else {
            cout<<"Positiin out of bound!!\n";
            delete(newnode);
        }

    }
}
void deletefront() {
    if(head == nullptr) {
        cout<<"The list is empt\n";
        
    } else {
       Node* temp = head;
       head = head->next;
       if(head != nullptr){
        head->prev = nullptr;
       } else{
        tail = nullptr;
       }
       delete(temp);
    }
}

void deleteend() {
    if(head == nullptr) {
        cout<<"The list is empty\n";
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
}
void deletepos(int k){
    if(head == nullptr){
        cout<<"The list is empty\n";

    } else {
        Node* temp = head;
        int count = 1;
        while(count < k && temp != nullptr){
            temp = temp->next;
            count++;
        }
        if(temp == nullptr){
            cout<<"The index out of bound\n";
        }
        if (temp == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    } else {
        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
    }

    delete temp; 
    }
}
void search(int k){
    Node* temp = head;
    int flag = false;
    int count = 1;
    while(temp != nullptr){
        if(temp->val == k){
            cout<<"The element is found at position "<<count<<"\n";
            break;
        }
        count++;
        temp = temp->next;
    }
}
void display() {
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
    return;
}
int main()
{
    int choice;
    while(true){
        cin>>choice;
        if(choice == 1){
            int a;
            cin>>a;
            insertfront(a);
        } else if(choice == 2){
            int a;
            cin>>a;
            insertend(a);
        } else if(choice == 3){
            int a,pos;
            cin>>a>>pos;
            insertpos(a,pos);
        } else if(choice == 4){
            deletefront();
        } else if(choice == 5){
            deleteend();
        } else if(choice == 6){
            int k;
            cin>>k;
            deletepos(k);
        } else if(choice == 7){
            int k;
            cin>>k;
            search(k);
        } else if(choice == 8){
            display();
        } else if(choice == 9){
            exit(0);
        }
    }
    return 0;
}