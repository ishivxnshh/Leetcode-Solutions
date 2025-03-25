#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (j < s.length() && i < t.length()) {
            if (s[j] == t[i])
                j++;
            i++;
        }
        return j == s.length();
    }
};

// Driver Code
int main() {
    Solution obj;
    
    vector<pair<string, string>> testCases = {
        {"abc", "ahbgdc"},  // Expected output: 1 (true)
        {"axc", "ahbgdc"},  // Expected output: 0 (false)
        {"", "ahbgdc"},     // Expected output: 1 (true)
        {"abc", ""},        // Expected output: 0 (false)
        {"b", "abc"},       // Expected output: 1 (true)
        {"acb", "ahbgdc"}   // Expected output: 0 (false)
    };

    for (auto &[s, t] : testCases) {
        cout << "s: " << s << ", t: " << t << " -> " << obj.isSubsequence(s, t) << endl;
    }

    return 0;
}
