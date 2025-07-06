#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1])
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    string word1 = "aabbcc";
    cout << "Possible String Count for \"" << word1 << "\": " << sol.possibleStringCount(word1) << endl;

    string word2 = "abcde";
    cout << "Possible String Count for \"" << word2 << "\": " << sol.possibleStringCount(word2) << endl;

    string word3 = "aaaaa";
    cout << "Possible String Count for \"" << word3 << "\": " << sol.possibleStringCount(word3) << endl;

    return 0;
}