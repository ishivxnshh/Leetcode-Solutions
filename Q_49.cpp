#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;
        for (auto str : strs) {
            string st = str;
            sort(str.begin(), str.end());
            mpp[str].push_back(st);
        }
        vector<vector<string>> vec;
        for (auto it : mpp) {
            vec.push_back(it.second);
        }
        return vec;
    }
};

// Function to print results
void printResult(const vector<vector<string>>& result) {
    cout << "Grouped Anagrams:\n";
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    cout << "---------------------------------\n";
}

// Driver code with pre-made test cases
int main() {
    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},  // Test Case 1
        {"hello", "world", "coding", "fun", "great"}, // Test Case 2
        {"abc", "cab", "bac"}, // Test Case 3 (All anagrams)
        {"bat", "bat", "tab", "tab", "bat"}, // Test Case 4 (Repeated words)
        {"a", "b", "a", "c", "b", "c"}, // Test Case 5 (Single character words)
        {"solitude"}, // Test Case 6 (Single word)
        {} // Test Case 7 (Empty input)
    };

    Solution sol;
    
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        vector<vector<string>> result = sol.groupAnagrams(testCases[i]);
        printResult(result);
    }

    return 0;
}
