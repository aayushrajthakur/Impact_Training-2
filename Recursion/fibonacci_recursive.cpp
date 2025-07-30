#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacci(int n){
    for(int i=0; i< n; i++){
        cout<<fibonacci(i)<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    
    printFibonacci(n);
    return 0;
}