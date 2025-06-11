#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for(char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.empty() || 
                    (c == ')' && stack.top() != '(') ||
                    (c == '}' && stack.top() != '{') ||
                    (c == ']' && stack.top() != '[')) {
                    return false;
                }
                stack.pop();
            }
        }
        
        return stack.empty();
    }
};

int main() {
    Solution solution;
    string s;
    
    // Take user input for the string of brackets
    cout << "Enter a string of brackets: ";
    cin >> s;
    
    // Check if the string of brackets is valid
    if (solution.isValid(s)) {
        cout << "The string is valid.\n";
    } else {
        cout << "The string is not valid.\n";
    }

    return 0;
}
