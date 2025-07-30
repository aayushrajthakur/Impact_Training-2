#include<iostream>
#include<vector>
using namespace std;

int romanToInteger(string roman){
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romanValue = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int integer = 0;
    for(int i=0;i<roman.size(); i++){
        for(int j=0;j< romanValue.size(); j++){
            if(roman[i] == romanValue[j]){

            }
        }
    }

}

int main()
{
    string romanValue;
    cin>>romanValue;
    cout<<romanToInteger(romanValue);
    return 0;
}