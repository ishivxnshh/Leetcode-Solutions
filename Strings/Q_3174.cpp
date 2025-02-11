#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {

        // Using Stack(tc: n, sc: n)
        // stack<char> stk;
        // for (auto it : s)
        // {
        //     if (it >= '0' && it <= '9')
        //     {
        //         stk.pop();
        //     }
        //     else
        //     {
        //         stk.push(it);
        //     }
        // }
        // string res = "";
        // while (!stk.empty())
        // {
        //     res += stk.top();
        //     stk.pop();
        // }

        // reverse(res.begin(), res.end());
        // return res;

        // Using string as a stack(tc:n, sc:n)
        string res;
        for(char ch:s)
        {
            if(isdigit(ch))
            {
                if(!res.empty())
                {
                    res.pop_back();
                }
            }
            else
            {
                res.push_back(ch);
            }
        }
        return res;
    }
};

// **Driver Code with Predefined Test Cases**
int main()
{
    Solution sol;

    // Test Cases
    string testCases[] = {
        "ab2c3d",     // Expected output: "a"
        "hello123",   // Expected output: "he"
        "abc123",     // Expected output: ""
        "a1b2c3d4",   // Expected output: ""
        "z9y8x7",     // Expected output: "z"
        "test0ing",   // Expected output: "testng"
        "a2b3c4d5e",  // Expected output: ""
        "1a2b3c",     // Expected output: ""
        "coding2024", // Expected output: "codi"
        "123456",     // Expected output: ""
    };

    // Running test cases
    for (int i = 0; i < 10; i++)
    {
        cout << "Input: " << testCases[i] << " -> Output: "
             << sol.clearDigits(testCases[i]) << endl;
    }

    return 0;
}
