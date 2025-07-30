#include<iostream>
using namespace std;

int main()
// {
//     int a=10, b;
//     b = a++ + ++a+a++ + ++a;
//     cout<<b;
//     return 0;
// }

{
    int a=10, b = 20, c;
    c = a+++++b;
    cout<<c<<" "<<b;
}