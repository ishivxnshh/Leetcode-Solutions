#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // Function to check if a word is consistent with the allowed characters
    bool check(string str, string allowed)
    {
        for (int i = 0; i < str.length(); i++)
        {
            int a = 0;
            for (int j = 0; j < allowed.length(); j++)
            {
                if (str[i] == allowed[j])
                {
                    a = 1;
                    break;
                }
            }
            if (a == 0)
                return false;
        }
        return true;
    }

    // Function to count the number of consistent strings
    int countConsistentStrings(string allowed, vector<string> &words)
    {

        // Brute-Force Approach (tc: O(k*m*n), sc: O(1))
        // int count = 0;
        // for (int i = 0; i < words.size(); i++) {
        //     if (check(words[i], allowed))
        //         count++;
        // }
        // return count;

        // Optimized Approach (tc: O(k*m + n), sc: O(1))
        unordered_set<char> allowed_set(allowed.begin(), allowed.end());
        int count = 0;
        // Iterate through each word
        for (const string &word : words)
        {
            bool consistent = true;
            for (char c : word)
            {
                if (allowed_set.find(c) == allowed_set.end())
                {
                    consistent = false;
                    break;
                }
            }
            if (consistent)
            {
                count++;
            }
        }
        return count;
    }
};

// Driver code to test multiple test cases
int main()
{
    Solution sol;

    // Test Case 1
    string allowed1 = "abc";
    vector<string> words1 = {"a", "b", "c", "ab", "ac", "bc", "abc", "def"};
    cout << "Test Case 1 Output: " << sol.countConsistentStrings(allowed1, words1) << endl;

    // Test Case 2
    string allowed2 = "xyz";
    vector<string> words2 = {"x", "xy", "xyz", "yy", "zz", "yx"};
    cout << "Test Case 2 Output: " << sol.countConsistentStrings(allowed2, words2) << endl;

    // Test Case 3
    string allowed3 = "mnop";
    vector<string> words3 = {"m", "n", "mo", "no", "mp", "pq", "mnop"};
    cout << "Test Case 3 Output: " << sol.countConsistentStrings(allowed3, words3) << endl;

    return 0;
}