#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
string postfixInfix(string postfix){
    stack<string> st;
    for(char ch : postfix){
        if(isOperator(ch)){
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();

            string temp = "(" + operand1 + " " + ch + " " + operand2 + ")";
            st.push(temp);
        }else {
            st.push(string(1, ch));

        }
    }
    return st.top();
}

int main()
{
    string s;
    cin>>s;


    string infix = postfixInfix(s);
    cout<<infix<<endl;
    return 0;
}