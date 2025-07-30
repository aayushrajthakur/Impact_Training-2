#include<iostream>
#include<stack>
using namespace std;

int main()
{
    bool visited[26] = {false};
    stack<char> st;
    string s;
    cin>>s;
    for(char c: s){
        if(!visited[c-'a']){
            st.push(c);
            visited[c-'a'] = true;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<"";
        st.pop();
    }

    return 0;
}