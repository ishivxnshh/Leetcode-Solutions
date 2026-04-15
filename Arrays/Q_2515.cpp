#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mini = n;

        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                int dist = abs(i - startIndex);
                mini = min({mini, dist, n - dist});
            }
        }

        return (mini == n) ? -1 : mini;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<string> words1 = {"hello", "i", "am", "leetcode", "hello"};
    string target1 = "hello";
    int startIndex1 = 1;
    cout << obj.closestTarget(words1, target1, startIndex1) << endl;
    // Expected: 1

    // Test Case 2
    vector<string> words2 = {"a", "b", "c", "d"};
    string target2 = "a";
    int startIndex2 = 0;
    cout << obj.closestTarget(words2, target2, startIndex2) << endl;
    // Expected: 0

    // Test Case 3
    vector<string> words3 = {"a", "b", "leetcode"};
    string target3 = "leetcode";
    int startIndex3 = 0;
    cout << obj.closestTarget(words3, target3, startIndex3) << endl;
    // Expected: 1

    // Test Case 4 (target not present)
    vector<string> words4 = {"a", "b", "c"};
    string target4 = "x";
    int startIndex4 = 2;
    cout << obj.closestTarget(words4, target4, startIndex4) << endl;
    // Expected: -1

    // Test Case 5 (wrap around case)
    vector<string> words5 = {"x", "y", "z", "a"};
    string target5 = "a";
    int startIndex5 = 0;
    cout << obj.closestTarget(words5, target5, startIndex5) << endl;
    // Expected: 1

    return 0;
}