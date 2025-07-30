#include<iostream>
#include<map>
using namespace std;

int main()
{
    int m;
    cin>>m;

    map<string, int> dict;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        dict[s]++;
    }
    int max = 0;
    string maxName ="";

    for(auto& it : dict){
        if(it.second> max){
            max = it.second;
            maxName = it.first;
        }
    }
    cout<<"The name having highest frequency is : "<<maxName;

    return 0;
}