#include <iostream>
#include <vector>

using namespace std;

bool isNum(string s) {
    if (s != "+" && s != "-" && s != "*" && s != "/") return true;
    else return false;
}

int evalRPN(vector<string>& tokens) {
    if (tokens.size() == 0) return 0;
    if (tokens.size() == 1) return atoi(tokens[0].c_str());
    int n = tokens.size();
    for (int i = 0; i < n / 2; ) {
        int j;
        vector<int> sym;
        for (j = 0; j < tokens.size() - 2; ) {
            if (isNum(tokens[j]) && isNum(tokens[j + 1]) && !isNum(tokens[j + 2])) {
                switch(tokens[j + 2][0]) {
                    case '+': tokens[j + 2] = to_string(atoi(tokens[j].c_str()) + atoi(tokens[j + 1].c_str())); break;
                    case '-': tokens[j + 2] = to_string(atoi(tokens[j].c_str()) - atoi(tokens[j + 1].c_str())); break;
                    case '*': tokens[j + 2] = to_string(atoi(tokens[j].c_str()) * atoi(tokens[j + 1].c_str())); break;
                    case '/': tokens[j + 2] = to_string(atoi(tokens[j].c_str()) / atoi(tokens[j + 1].c_str())); break;
                }
                sym.push_back(j + 2);
                j += 3;
            } else j++;
        }
        vector<string>::iterator it;
        for (j = sym.size() - 1; j >= 0; j--) {
            it = tokens.begin() + sym[j] - 2;
            it = tokens.erase(it);
            it = tokens.erase(it);   
        }
        i += sym.size();
    }
    return atoi(tokens[0].c_str());
}