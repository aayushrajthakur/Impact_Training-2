#include<iostream>
using namespace std;

class Cat{
    public:
    string name = "Kitty";
    string color = "Brown";
    int age = 2;
    void sound(){
        cout<<"Meow";
    }
};
int main()
{
    Cat persian;
    cout<<"Cat's Name : "<<persian.name<<"\n";
    cout<<"Cat's color : "<<persian.color<<"\n";
    cout<<"Cat's age : "<<persian.age<<"\n";
    cout<<"Cat's sound : ";
    persian.sound();
    return 0;
}