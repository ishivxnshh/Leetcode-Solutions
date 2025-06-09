#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int beautySum(string s) {
    /*
    Time Complexity: O(N^2 * 26) ≈ O(N^2), where N is the length of the string.
        - Outer loop runs O(N) times.
        - Inner loop runs up to O(N) times for each i.
        - For each substring, we scan 26 characters to find min/max.

    Space Complexity: O(26) = O(1), for the frequency array.
    */
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n - 2; i++)
    {
        vector<int> ans(26, 0);
        for(int j = i; j < n; j++)
        {
            ans[s[j] - 'a']++;
            int mini = INT_MAX, maxi = 0;
            for(int k = 0; k < 26; k++)
            {
                maxi = max(maxi, ans[k]);
                if(ans[k] != 0) mini = min(mini, ans[k]);
            }
            cnt += (maxi - mini);
        }
    }
    return cnt;
}

// Driver code with premade test cases
int main() {
    vector<pair<string, int>> testcases = {
        {"aabcb", 5},
        {"aabcbaa", 17},
        {"abc", 0},
        {"aaaa", 0}
    };

    for (const auto& tc : testcases) {
        int result = beautySum(tc.first);
        cout << "Input: \"" << tc.first << "\" | Expected: " << tc.second << " | Got: " << result;
        if (result == tc.second) cout << " | PASS";
        else cout << " | FAIL";
        cout << endl;
    }
    return 0;
}