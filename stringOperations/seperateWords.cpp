#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);
    string temp;
    vector<string> arr;

    while(ss >> temp){
        arr.push_back(temp);
    }

    for(int i=0; i< arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}