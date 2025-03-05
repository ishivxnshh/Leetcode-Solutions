// Time Complexity: O(N + M), where N is the total length of words1 and M is the total length of words2
// Space Complexity: O(1), as we only use a fixed-size array of 26 characters

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> count(string word) 
    {
        vector<int> counts(26, 0);
        for(char c : word)
        {
            counts[c - 'a']++;
        }
        return counts;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int> bMax(26, 0);
        
        for(const string& b : words2)
        {
            vector<int> bCount = count(b);
            for(int i = 0; i < 26; i++)
            {
                bMax[i] = max(bMax[i], bCount[i]);
            }
        }

        vector<string> resultant_vec;
        
        for(const string& a : words1)
        {
            int isSubset = true;
            vector<int> aCount = count(a);
            
            for(int i = 0; i < 26; i++)
            {
                if(aCount[i] < bMax[i])
                {
                    isSubset = false;
                }
            }

            if(isSubset)
            {
                resultant_vec.push_back(a);
            }
        }
        return resultant_vec;
    }
};

// Driver Code
int main() 
{
    Solution sol;
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};

    vector<string> result = sol.wordSubsets(words1, words2);

    cout << "Universal words: ";
    for(const string& word : result)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}