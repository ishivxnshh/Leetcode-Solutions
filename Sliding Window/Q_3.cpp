#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                if (mpp[s[j]] > 1) {
                    break;
                }
                maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};

int main() {
    Solution solution;

    // Pre-made test cases
    vector<string> testCases = {
        "abcabcbb",  // Expected output: 3
        "bbbbb",     // Expected output: 1
        "pwwkew",    // Expected output: 3
        "",          // Expected output: 0
        "abcdef",    // Expected output: 6
        "abba",      // Expected output: 2
        "dvdf"       // Expected output: 3
    };

    cout << "Running pre-made test cases:\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        string testCase = testCases[i];
        int result = solution.lengthOfLongestSubstring(testCase);
        cout << "Test Case " << i + 1 << ": \"" << testCase << "\"\n";
        cout << "Output: " << result << "\n\n";
    }

    return 0;
}
