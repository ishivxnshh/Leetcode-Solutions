#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string res = "";
        while (i < word1.size() && j < word2.size())
        {
            res += word1[i++];
            res += word2[j++];
        }
        while (i < word1.size())
            res += word1[i++];
        while (j < word2.size())
            res += word2[j++];
        return res;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    string word1 = "abc";
    string word2 = "pqr";
    cout << "Merged: " << sol.mergeAlternately(word1, word2) << endl;
    // Output: "apbqcr"

    word1 = "ab";
    word2 = "pqrs";
    cout << "Merged: " << sol.mergeAlternately(word1, word2) << endl;
    // Output: "apbqrs"

    word1 = "abcd";
    word2 = "pq";
    cout << "Merged: " << sol.mergeAlternately(word1, word2) << endl;
    // Output: "apbqcd"

    return 0;
}