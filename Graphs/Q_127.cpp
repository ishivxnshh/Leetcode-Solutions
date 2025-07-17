#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /*
        Time Complexity (TC): O(N * L * 26) ≈ O(N * L)
            - N: number of words in wordList
            - L: length of each word
            - 26: constant for trying all lowercase letters

        Space Complexity (SC): O(N * L)
            - O(N * L): for storing all words in unordered_set
            - O(N): for the BFS queue in the worst case
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            string original = word;
            if (word == endWord) return steps;

            for (int i = 0; i < word.length(); i++) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {  // 26 lowercase letters
                    word[i] = ch;
                    if (words.find(word) != words.end()) {
                        q.push({word, steps + 1});
                        words.erase(word);
                    }
                }
                word = original;
            }
        }

        return 0;
    }
};

// Driver Code
int main() {
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Minimum number of steps: " << result << endl;

    return 0;
}