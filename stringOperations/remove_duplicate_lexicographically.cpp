#include<bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    unordered_map<char, int> freq;
    unordered_set<char> seen;
    stack<char> st;

    for(char ch : s) freq[ch]++;

    for(char ch : s){
        freq[ch]--;

        if(seen.count(ch)) continue;

        while((!st.empty()) && freq[st.top()] > ch && freq[st.top()] > 0) {
            seen.erase(st.top());
            st.pop();
        }

        st.push(ch);
        seen.insert(ch);
    }

    string res ;
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;

}

int main()
{
    string inp;
    cin>>inp;

    cout<< removeDuplicate(inp);

    return 0;
}