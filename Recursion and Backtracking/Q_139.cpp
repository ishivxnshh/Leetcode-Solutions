#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<string> st;
    int n;
    int t[301];

    bool solve(int idx, string s)
    {
        if (idx == n) return true;

        if (t[idx] != -1) return t[idx];

        if (st.find(s) != st.end()) return true;

        for (int l = 0; l <= n; l++)
        {
            string temp = s.substr(idx, l);

            if (st.find(temp) != st.end() && solve(idx + l, s))
            {
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        n = s.length();

        memset(t, -1, sizeof(t));

        for (string &word : wordDict)
        {
            st.insert(word);
        }

        return solve(0, s);
    }
};

int main()
{
    Solution obj;

    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    cout << obj.wordBreak(s1, dict1) << endl;

    Solution obj2;
    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << obj2.wordBreak(s2, dict2) << endl;

    Solution obj3;
    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << obj3.wordBreak(s3, dict3) << endl;

    Solution obj4;
    string s4 = "cars";
    vector<string> dict4 = {"car", "ca", "rs"};
    cout << obj4.wordBreak(s4, dict4) << endl;

    return 0;
}
