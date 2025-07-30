#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Accounts{
    public:
    string accountNumber;
    string accountName;

    
    Accounts(string accountNumber, string accountName){
        this->accountName = accountName;
        this->accountNumber = accountNumber;
    }
};

class SavingAccounts: public Accounts{
    public:
    double balance;

    
    SavingAccounts( string accountNumber, string accountName, double balance): Accounts(accountNumber, accountName) {
        this->balance = balance;
    }
};

class FixedAccounts: public SavingAccounts {
    public:
    double interestRate;

    
    FixedAccounts( string accountNumber, string accountName,double balance, double interestRate): SavingAccounts(accountNumber, accountName, balance) {
        this->interestRate = interestRate;
    }

    void displayDetails() {
        cout<<"Account Number : "<<accountNumber<<endl;
        cout<<"Account Name : "<< accountName<<endl ;
        cout<<"Balance : "<< balance <<endl;
        cout<<"Interest per year : "<< interestRate <<endl ;
    }
};

int main() {

    string input;
    cout<<"Enter your comma's seperated account details : ";
    getline(cin, input);
    vector<string> details1;
    vector<double> details2;

    stringstream ss(input);
    string temp;

    while(getline(ss, temp, ',')){
        stringstream converter(temp);

        if(temp.find('.') != string::npos){
            double val;
            converter >> val;
            details2.push_back(val);
        }else {
            string val;
            converter >> val;
            details1.push_back(val);
        }
    }

    FixedAccounts account(details1[0], details1[1], details2[0], details2[1]);
    account.displayDetails();
}