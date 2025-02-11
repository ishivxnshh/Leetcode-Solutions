#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> st;
        map<char, char> ts;
        if(s.size()!=t.size())
            return false;
        bool check = true;
        for(int i=0;i<s.size();i++)
        {
            if(st.find(s[i])!=st.end())
            {
                if(st[s[i]]!=t[i])
                    return false;
            }
            st[s[i]] = t[i];

            if(ts.find(t[i])!=ts.end())
            {
                if(ts[t[i]]!=s[i])
                    return false;
            }
            ts[t[i]] = s[i];
        }
        return check;
    }
};

// Driver code
int main()
{
    Solution sol;
    
    // Sample test cases
    vector<pair<string, string>> testCases = {
        {"egg", "add"},   // true
        {"foo", "bar"},   // false
        {"paper", "title"}, // true
        {"badc", "baba"}  // false
    };

    for (auto &testCase : testCases)
    {
        cout << "isIsomorphic(\"" << testCase.first << "\", \"" << testCase.second << "\") = ";
        cout << (sol.isIsomorphic(testCase.first, testCase.second) ? "true" : "false") << endl;
    }

    return 0;
}
