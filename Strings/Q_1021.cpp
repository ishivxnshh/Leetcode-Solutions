#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        // My Approach
        // stack<char> stk;
        // string s1 = "";
        // for (auto ch : s)
        // {
        //     if (stk.size() == 0)
        //     {
        //         stk.push(ch);
        //     }
        //     else if (stk.size() == 1 && ch == ')')
        //     {
        //         stk.pop();
        //     }
        //     else if (ch == '(')
        //     {
        //         stk.push(ch);
        //         s1 += ch;
        //     }
        //     else
        //     {
        //         stk.pop();
        //         s1 += ch;
        //     }
        // }
        // return s1;

        // Optimized Approach with less condition checking
        stack<char> stk;
        string s1 = "";
        for (auto ch : s)
        {
            if (ch == '(')
            {
                if (stk.size() > 0) // Only add '(' if it's not the outermost
                    s1 += ch;
                stk.push(ch);
            }
            else
            {
                stk.pop();
                if (stk.size() > 0) // Only add ')' if it's not the outermost
                    s1 += ch;
            }
        }
        return s1;
    }
};
// Driver Code
int main()
{
    Solution sol;

    // Test Case 1
    string s1 = "(()())(())";
    cout << "Test Case 1: " << sol.removeOuterParentheses(s1) << endl; // Expected Output: "()()()"

    // Test Case 2
    string s2 = "(()())(())(()(()))";
    cout << "Test Case 2: " << sol.removeOuterParentheses(s2) << endl; // Expected Output: "()()()()(())"

    // Test Case 3
    string s3 = "()()";
    cout << "Test Case 3: " << sol.removeOuterParentheses(s3) << endl; // Expected Output: ""

    return 0;
}