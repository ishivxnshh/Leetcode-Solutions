#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        stk.push(-1); // To handle the edge case where the valid substring
                      // starts from the beginning
        int max_len = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i); // Store the index of the '('
            }
            else
            {
                stk.pop(); // Pop the last element (matching '(')
                if (stk.empty())
                {
                    stk.push(i); // Push the current index as the new base for
                                 // the next valid substring
                }
                else
                {
                    max_len = max(max_len, i - stk.top()); // Calculate the length of
                                                           // valid parentheses
                }
            }
        }
        return max_len;
    }
};

int main()
{
    Solution sol;

    // Test Case 1: Basic case with balanced parentheses
    string test1 = "(()())";
    cout << "Test Case 1: " << sol.longestValidParentheses(test1) << endl; // Expected Output: 6

    // Test Case 2: Case with no valid parentheses
    string test2 = "(((((";
    cout << "Test Case 2: " << sol.longestValidParentheses(test2) << endl; // Expected Output: 0

    // Test Case 3: Case with only valid parentheses
    string test3 = "()()()";
    cout << "Test Case 3: " << sol.longestValidParentheses(test3) << endl; // Expected Output: 6

    // Test Case 4: Complex nested parentheses
    string test4 = "((())())";
    cout << "Test Case 4: " << sol.longestValidParentheses(test4) << endl; // Expected Output: 8

    // Test Case 5: Case with alternating parentheses
    string test5 = "()(()";
    cout << "Test Case 5: " << sol.longestValidParentheses(test5) << endl; // Expected Output: 2

    // Test Case 6: Empty string
    string test6 = "";
    cout << "Test Case 6: " << sol.longestValidParentheses(test6) << endl; // Expected Output: 0

    // Test Case 7: Case with a very large valid parentheses string
    string test7 = "()()()()()()()()()()()()()()()()";
    cout << "Test Case 7: " << sol.longestValidParentheses(test7) << endl; // Expected Output: 32

    return 0;
}
