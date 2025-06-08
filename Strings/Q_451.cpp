#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        // Brute-Force Approach (tc: O(n log n), sc: O(1))
        // vector<int> freq(128, 0);
        // for (auto ch : s)
        // {
        //     freq[ch]++;
        // }
        // auto cmp = [&](char a, char b)
        // {
        //     if (freq[a] == freq[b])
        //     {
        //         return a < b;
        //     }
        //     return freq[a] > freq[b];
        // };
        // sort(s.begin(), s.end(), cmp);
        // return s;

        // Better Approach (tc: O(N + K log K) = O(N), sc: O(N + K))
        // unordered_map<char, int> freq;
        // for (auto ch : s) freq[ch]++;
        // vector<pair<char, int>> freqArr;
        // for(auto [ch, fq] : freq) freqArr.push_back({ch, fq});
        // auto cmp = [&](pair<char, int>& a, pair<char, int>& b) {
        //     return a.second > b.second;
        // };
        // sort(freqArr.begin(), freqArr.end(), cmp);
        // string ans = "";
        // for(auto [ch, fq] : freqArr) ans.append(fq, ch);
        // return ans;

        // Optimal Approach (using bucket sort) (tc: O(N), sc: O(N))
        unordered_map<char, int> freq;
        for(auto ch : s) freq[ch]++;
        vector<vector<char>> bucketData(s.length() + 1);
        for(auto [ch, fq] : freq) bucketData[fq].push_back(ch);
        string ans = "";
        for(int freq = s.length(); freq >= 1; freq--)
        {
            for(auto ch : bucketData[freq])
                ans.append(freq, ch);
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    string s1 = "tree";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.frequencySort(s1) << endl;

    // Test Case 2
    string s2 = "cccaaa";
    cout << "\nInput: " << s2 << endl;
    cout << "Output: " << obj.frequencySort(s2) << endl;

    // Test Case 3
    string s3 = "Aabb";
    cout << "\nInput: " << s3 << endl;
    cout << "Output: " << obj.frequencySort(s3) <<
