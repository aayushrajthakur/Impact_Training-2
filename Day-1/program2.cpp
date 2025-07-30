#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a;
    cout <<"Enter a number : ";
    cin >> a;
    if(a%5==0){
        cout<<"Hi ";
    }
    if(a%3==0){
        cout<<"Hello";
    }
    return 0;
}