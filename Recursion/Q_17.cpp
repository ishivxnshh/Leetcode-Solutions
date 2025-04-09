// Time Complexity: O(4^n)
// Space Complexity: O(n)
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(int index, string &digits, string &current, vector<string> &result, vector<string> &phone)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters = phone[digits[index] - '0' - 2];
        for (char ch : letters)
        {
            current.push_back(ch);
            backtrack(index + 1, digits, current, result, phone);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current = "";
        backtrack(0, digits, current, result, phone);
        return result;
    }
};

// Driver Code
int main()
{
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);
    
    cout << "Letter Combinations: ";
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
