#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
    string sentence;
    cout<<"Enter the string: ";
    deque<char> de;
    getline(cin,sentence);

    for(char c: sentence){
        de.push_back(c);
    }
    
    while(!de.empty()){
        cout<<de.back();
        de.pop_back();
    }
    return 0;
}