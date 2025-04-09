// Time Complexity: O(2^n) in the worst case due to recursion and subset generation.
// Space Complexity: O(n) for the recursion stack (excluding the result storage).

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void combinations(int ind, vector<int>& candidates, int target , vector<int> vec, vector<vector<int>>& res) 
    {
        if (target == 0)
        {
            res.push_back(vec);
        }
        for (int i = ind; i < candidates.size(); i++)
        {
            if (i > ind && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }
            vec.push_back(candidates[i]);
            combinations(i + 1, candidates, target - candidates[i], vec, res);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        combinations(0, candidates, target, vector<int>(), res);
        return res;
    }
};

// Driver Code
int main() 
{
    Solution obj;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = obj.combinationSum2(candidates, target);
    
    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& comb : result) 
    {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) 
        {
            cout << comb[i];
            if (i != comb.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    
    return 0;
}