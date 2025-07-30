#include<iostream>
#include <vector>
#include<map>
using namespace std;


void find_all_Possibilities(int idx, string& digits, vector<string>& v, string s, map<char, string> m){
    if(idx == digits.size()){
        v.push_back(s);
        return;
    }

    string t = m[digits[idx]];
    for(int i=0; i< t.size(); i++){
        s += t[i];
        find_all_Possibilities(idx+1, digits, v, s, m);
        s.pop_back();
    }
}
vector<string> findCombination(string digits){
    vector<string> v;
    if(digits.size() == 0){
        return v;
    }
    string s;
    map<char, string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";

    find_all_Possibilities(0, digits, v, s, m);
    return v;
}

int main()
{
    string s;
    cout<<"Enter the telephone numbeer digit without any space: ";
    cin>>s;

    vector<string> res = findCombination(s);
    cout<<"Total Combinations : ";
    for(int i=0; i< res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}