#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

string infixToPrefix(string s){
    stack<char> st;
    reverse(s.begin(), s.end());

    for(int i=0; i< s.length(); i++){
        if(s[i] == ')') {
            s[i] = '(';
        }else if(s[i] == '('){
            s[i] = ')';
        }
    }

    string postfix = "";

    for(char ch : s){
        if(isalnum(ch)){
            postfix += ch;
        }else if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }else {
            while(!st.empty() && precedence(ch) < precedence(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main()
{
    string infix;
    cin>>infix;

    cout<<infixToPrefix(infix);
    return 0;
}