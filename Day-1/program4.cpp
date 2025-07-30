#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter two number :";
    int a,b,c;
    cin >> a;
    cin >>b;
    c = (a+b+abs(a-b))/2;
    cout<<"The max value is : ";
    cout <<(c);

    return 0;
}