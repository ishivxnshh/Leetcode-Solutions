#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool palindrome(string& s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void backtrackKro(int ind, string& s, vector<string> temp, vector<vector<string>>& res)
    {
        if (ind == s.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            if (palindrome(s, ind, i))
            {
                temp.push_back(s.substr(ind, i - ind + 1));
                backtrackKro(i + 1, s, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        backtrackKro(0, s, vector<string>(), res);
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "aab";

    vector<vector<string>> result = sol.partition(s);

    cout << "Palindrome Partitions of \"" << s << "\":" << endl;

    for (const auto& partition : result)
    {
        cout << "[ ";
        for (const string& word : partition)
        {
            cout << "\"" << word << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}