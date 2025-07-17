#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

//         unordered_set<string> words(wordList.begin(), wordList.end());
//         queue<vector<string>> q;
//         q.push({beginWord});
//         unordered_set<string> usedOnLevel;
//         usedOnLevel.insert(beginWord);
//         vector<vector<string>> ans;
//         int level = 0;

//         while (!q.empty())
//         {
//             auto vec = q.front(); q.pop();
//             if (vec.size() > level)
//             {
//                 level++;
//                 for (auto it : usedOnLevel)
//                 {
//                     words.erase(it);
//                 }
//                 usedOnLevel.clear();
//             }

//             string word = vec.back();
//             if (word == endWord)
//             {
//                 if (ans.size() == 0)
//                     ans.push_back(vec);
//                 else if (ans[0].size() == vec.size())
//                     ans.push_back(vec);
//                 else break;
//             }

//             for (int i = 0; i < word.length(); i++)
//             {
//                 char original = word[i];
//                 for (char ch = 'a'; ch <= 'z'; ++ch)
//                 {
//                     if (ch == original) continue;
//                     word[i] = ch;
//                     if (words.find(word) != words.end())
//                     {
//                         vec.push_back(word);
//                         q.push(vec);
//                         usedOnLevel.insert(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i] = original;
//             }
//         }

//         return ans;
//     }
// };

// Time Complexity: O(N * L * 26)
// Space Complexity: O(N * L)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};

        unordered_map<string, int> levels;
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        levels[beginWord] = 0;

        int minLevel = INT_MAX;
        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> usedOnLevel;

            for (int i = 0; i < size; i++) {
                auto [word, level] = q.front(); q.pop();

                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;
                        if (wordSet.find(word) != wordSet.end()) {
                            if (!levels.count(word)) {
                                levels[word] = level + 1;
                                q.push({word, level + 1});
                                usedOnLevel.insert(word);
                            }
                        }
                    }
                    word[j] = original;
                }
            }

            // Remove words after processing the level
            for (const string& word : usedOnLevel) {
                wordSet.erase(word);
            }
        }

        // Early exit if endWord was never reached
        if (!levels.count(endWord)) return {};

        // DFS for path building
        vector<vector<string>> result;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, levels, path, result);
        return result;
    }

    void dfs(string word, const string& beginWord,
             unordered_map<string, int>& levels,
             vector<string>& path,
             vector<vector<string>>& result) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        int currentLevel = levels[word];

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (levels.count(word) && levels[word] == currentLevel - 1) {
                    path.push_back(word);
                    dfs(word, beginWord, levels, path, result);
                    path.pop_back();
                }
            }
            word[i] = original;
        }
    }
};


// Driver Code
int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    cout << "Shortest transformation sequences:\n";
    for (auto path : result) {
        for (auto word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}