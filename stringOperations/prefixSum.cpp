#include<iostream>
#include <vector>
using namespace std;
string prefixsum(string s, vector<int>& shifts){
    for(int i=0; i< s.length(); i++){
        for(int j=0; j<= i; j++){
            char t = s[j]+ shifts[j];
            if(t > 'a'+ 26){
                t  = t% ('a'+ 26);
            }
            s[j] = t;
        }
    }
    return s;
}
int main()
{
    string s;
    cin>>s;

    vector<int> arr(s.length());
    for(int i=0; i< arr.size(); i++){
        cin>>arr[i];
    }

    string s = prefixsum(s, arr);
    cout<<s;
    return 0;
}