#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int, string> dict {{104, "A"}, {102, "B"}, {103, "C"}, {101, "D"}};

    if(dict.count(107)){
        cout<<"Key found"<<endl;
    }else {
        cout<<"Not found"<<endl;
    }

    
    for(auto it : dict){
        cout<<it.first<<" : "<<it.second<<endl;
    }
    return 0;
}