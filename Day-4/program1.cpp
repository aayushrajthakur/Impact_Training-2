#include<iostream>
using namespace std;

int main()
{
    int a= 10;
    int &b = a;
    int* c = &b;

    //cout<<&a<<endl<<&b;
    //* is used to dereference the pointer
    //& is used to get the address of the variable
    cout<<c;
    //cout<<&b;

    return 0;
}