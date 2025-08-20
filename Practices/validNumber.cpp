#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isValidNumber(const std::string& s) {
    regex pattern(R"(^\s*[+-]?((\d+(\.\d*)?)|(\.\d+))(e[+-]?\d+)?\s*$)", std::regex::icase);
    return regex_match(s, pattern);
}

int main() {
    std::vector<std::string> tests = {
        "123", "-123", "3.14", "-.9", "0.", ".5", "2e10", "-3.5E-2",
        "abc", "1a", "e9", "--6", "99e2.5"
    };

    for (const auto& s : tests) {
        std::cout << "\"" << s << "\" is " << (isValidNumber(s) ? "valid" : "invalid") << "\n";
    }
}
