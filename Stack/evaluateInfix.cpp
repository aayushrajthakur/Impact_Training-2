#include<iostream>
#include<sstream>
#include<string>
#include<stack>
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

int evaluatePostfix(string s){
    stack<int> st;
    

    for(char token : s){
        if(isdigit(token)){
            st.push(token - '0');
        }else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            switch(token){
                case '+': st.push(a+ b); break;

                case '-': st.push(b - a); break;
                case '*': st.push(a*b); break;
                case '/': st.push(b / a); break;
            }
        }
    }

    return st.top();
}
int evaluate(string s){
    string postfix = infixPostfix(s);
    int res = evaluatePostfix(postfix);
    return res;

}

int main()
{
    string infix;
    cin>> infix;
    cout<<"The output is : ";
    cout<<evaluate(infix);
    return 0;
}