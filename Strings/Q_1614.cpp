#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        // Brute-Force Approach (tc: O(n), sc: O(n))
        // stack<char> stk;
        // int maxi = 0;
        // int count = 0;
        // for (auto ch : s)
        // {
        //     if (ch == '(')
        //     {
        //         stk.push('(');
        //         count++;
        //     }
        //     else if (ch == ')')
        //     {
        //         maxi = max(maxi, count);
        //         count--;
        //         stk.pop();
        //     }
        // }
        // return maxi;

        // Optimal Approach (tc: O(n), sc: O(1))
        int depth = 0;
        int maxDepth = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (ch == ')')
            {
                depth--;
            }
        }
        return maxDepth;
    }
};

// Driver Code
int main()
{
    Solution sol;
    
    string test1 = "(1+(2*3)+((8)/4))+1";
    cout << "Max Depth of test1: " << sol.maxDepth(test1) << endl;

    string test2 = "(1)+((2))+(((3)))";
    cout << "Max Depth of test2: " << sol.maxDepth(test2) << endl;

    string test3 = "1+(2*3)/(2-1)";
    cout << "Max Depth of test3: " << sol.maxDepth(test3) << endl;

    string test4 = "1";
    cout << "Max Depth of test4: " << sol.maxDepth(test4) << endl;

    return 0;
}
