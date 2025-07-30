#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixPostfix(string s){
    stack<char> st;
    string post = "";

    for(char ch : s){
        if(isalnum(ch)){
            post += ch;
        }else if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                post += st.top();

                st.pop();
            }
            st.pop();
        }else {
            while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                post += st.top();

                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        post += st.top();
        st.pop();
    }

    return post;


}

int main()
{
    string infix = "(a-b/c)*(a/k-l)";

    cout<< infixPostfix(infix);
    return 0;
}