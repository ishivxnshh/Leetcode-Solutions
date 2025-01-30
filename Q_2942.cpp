#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> idx;
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                if (ch == x) {
                    idx.push_back(i);
                    break;
                }
            }
        }
        return idx;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1: General case
    vector<string> words1 = {"apple", "banana", "cherry", "date"};
    char x1 = 'a';
    vector<int> result1 = solution.findWordsContaining(words1, x1);
    cout << "Indices containing '" << x1 << "': ";
    for (int idx : result1) {
        cout << idx << " ";
    }
    cout << endl;

    // Test Case 2: Character not present in any word
    vector<string> words2 = {"hello", "world", "test"};
    char x2 = 'z';
    vector<int> result2 = solution.findWordsContaining(words2, x2);
    cout << "Indices containing '" << x2 << "': ";
    for (int idx : result2) {
        cout << idx << " ";
    }
    cout << endl;

    // Test Case 3: All words contain the character
    vector<string> words3 = {"aaa", "aba", "aab"};
    char x3 = 'a';
    vector<int> result3 = solution.findWordsContaining(words3, x3);
    cout << "Indices containing '" << x3 << "': ";
    for (int idx : result3) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
