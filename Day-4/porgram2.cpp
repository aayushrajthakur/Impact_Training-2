#include<iostream>
using namespace std;
void show(int* a){
    cout<<*a<<endl;
    *a++;
    cout<<*a;
}
int main()
{
    int n = 10;
    show(&n);
    cout<<n;
    return 0;
}