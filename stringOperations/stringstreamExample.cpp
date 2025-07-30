#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string input = "1234,45.78,Hello,78,World,3.141"; // Hardcoded input

    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ',')) { 
        stringstream converter(temp);

        if (temp.find('.') != string::npos) { // Check if it's a float
            float floatVal;
            converter >> floatVal;
            cout << "Float: " << floatVal << endl;
        } 
        else if (isdigit(temp[0])) { // Check if it's an integer
            int intVal;
            converter >> intVal;
            cout << "Integer: " << intVal << endl;
        } 
        else { // Otherwise, treat as a string
            cout << "String: " << temp << endl;
        }
    }

    return 0;
}
