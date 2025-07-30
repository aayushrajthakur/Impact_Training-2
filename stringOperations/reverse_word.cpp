#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse_word(string s){
    stack<string> st;
    string temp = "";
    for(int i=0; i< s.length(); i++){
        if(s[i] != ' '){
            temp += s[i];
        }else {
            st.push(temp);
            temp = "";
        }
        
    }
    st.push(temp);
    while(!st.empty()){
        cout<<st.top()<<" "; st.pop();
    }

}

int main()
{
    string inp;
    getline(cin, inp);


    string res= reverse_word(inp);
    return 0;
}