#include<iostream>
#include<vector>
using namespace std;


string romanConversion(int num){
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> syb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string res = "";
    for(int i=0;i< val.size(); i++){
        while(num >= val[i]){
            res += syb[i];
            num -= val[i];
        }
    }

    return res;
}

int main()
{
    int num;
    cin>>num;

    string res = romanConversion(num);
    cout<<"Roman value : "<<res;
    return 0;
}