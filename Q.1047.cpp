#include <iostream>
#include <stack>
#include <algorithm> // for reverse
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
         stack<char> stk;

         for(char ch : s) {
            if(!stk.empty() && stk.top() == ch) {
                stk.pop();
            } else {
                stk.push(ch);
            }
         }      

         string result;
         while(!stk.empty()) {
            result += stk.top();
            stk.pop();
         }

         reverse(result.begin(), result.end());
         return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "abbaca";
    string result1 = solution.removeDuplicates(s1);
    cout << "Test case 1 - Expected: ca, Got: " << result1 << endl;

    // Test case 2
    string s2 = "azxxzy";
    string result2 = solution.removeDuplicates(s2);
    cout << "Test case 2 - Expected: ay, Got: " << result2 << endl;

    return 0;
}
