#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.length())
            return "0";
        stack<char> stk;
        for (int i = 0; i < num.size(); i++)
        {
            while (!stk.empty() && k > 0 && num[i] < stk.top())
            {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while (k--)
        {
            stk.pop();
        }
        if (stk.empty())
            return "0";
        string res = "";
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while (i < res.length() && res[i] == '0')
        {
            i++;
        }
        if (res.substr(i).empty())
            return "0";
        else
            return res.substr(i);
    }
};

int main()
{
    Solution sol;

    // Sample test cases
    vector<pair<string, int>> testCases = {
        {"1432219", 3},   // Output: "1219"
        {"10200", 1},     // Output: "200"
        {"10", 2},        // Output: "0"
        {"9", 1},         // Output: "0"
        {"1234567890", 9} // Output: "0"
    };

    for (auto &[num, k] : testCases)
    {
        cout << "Input: " << num << ", k = " << k << " → Output: " << sol.removeKdigits(num, k) << endl;
    }

    return 0;
}
