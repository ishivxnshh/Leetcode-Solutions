#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> h(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            h[s[i] - 'a']++;
            h[t[i] - 'a']--;
        }
        for (int count : h)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Driver Code
int main()
{
    Solution sol;
    
    string s1 = "anagram", t1 = "nagaram";
    cout << (sol.isAnagram(s1, t1) ? "true" : "false") << endl; // Expected output: true

    string s2 = "rat", t2 = "car";
    cout << (sol.isAnagram(s2, t2) ? "true" : "false") << endl; // Expected output: false

    string s3 = "listen", t3 = "silent";
    cout << (sol.isAnagram(s3, t3) ? "true" : "false") << endl; // Expected output: true

    string s4 = "hello", t4 = "world";
    cout << (sol.isAnagram(s4, t4) ? "true" : "false") << endl; // Expected output: false

    return 0;
}