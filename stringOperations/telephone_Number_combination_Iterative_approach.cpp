#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<string> findCombinations(string s){
    map<char, string> m {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> res;
    if(s.size() == 0) return res;

    res.push_back("");

    for(char ch: s){
        vector<string> temp;
        for(string combinations: res){
            for(char c: m[ch]){
                temp.push_back(combinations + c);
            }
        }
        res.swap(temp);
    }
    return res;
}

int main()
{
    string s;
    cin>>s;

    vector<string> res  = findCombinations(s);
    cout<<"Total possible combinations : ";
    for(int i=0; i< res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}