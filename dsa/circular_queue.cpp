#include<iostream>
using namespace std;
#define size 5
int rear = -1;
int front = -1;
int queue[size];

void push(int a){
    if(front == -1 && rear == -1){
        front = 0;
        queue[++rear] = a;

    }else if(front == (rear+1)%size){
        cout<<"Queue is full\n";
    }else {
        
    }
}

int main()
{
    
    return 0;
}