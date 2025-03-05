#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> vec = {words[0]};
        sort(words[0].begin(), words[0].end());
        string check = words[0];
        string a;
        for (int i = 1; i < words.size(); i++)
        {
            a = words[i];
            sort(words[i].begin(), words[i].end());
            if (words[i] != check)
            {
                vec.push_back(a);
                check = words[i];
            }
        }
        return vec;
    }
};

int main()
{
    vector<vector<string>> testCases = {
        {"abba", "baba", "bbaa", "cd", "dc", "efg"},
        {"a", "b", "c", "d", "e"},
        {"abc", "bca", "cab", "xyz", "yxz", "zxy"},
        {"hello", "olleh", "world", "dlrow", "test"}};

    vector<vector<string>> expectedOutputs = {
        {"abba", "cd", "efg"},
        {"a", "b", "c", "d", "e"},
        {"abc", "xyz"},
        {"hello", "world", "test"}};

    Solution solution;
    cout << "Executing predefined test cases...\n";

    for (int i = 0; i < testCases.size(); ++i)
    {
        vector<string> result = solution.removeAnagrams(testCases[i]);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Words: ";
        for (const string &word : testCases[i])
        {
            cout << word << " ";
        }
        cout << "\nExpected Output: ";
        for (const string &word : expectedOutputs[i])
        {
            cout << word << " ";
        }
        cout << "\nActual Output: ";
        for (const string &word : result)
        {
            cout << word << " ";
        }
        cout << "\n"
             << (result == expectedOutputs[i] ? "Test Passed" : "Test Failed") << "\n";
        cout << "--------------------------\n";
    }

    return 0;
}