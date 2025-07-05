#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void generateComb(int i, vector<int>& candidates, int target, vector<int> vec, vector<vector<int>> &res)
    {
        if(i == candidates.size())
        {
            if(target == 0)
                res.push_back(vec);
            return;
        }
        if(candidates[i] <= target)
        {
            vec.push_back(candidates[i]);
            generateComb(i, candidates, target - candidates[i], vec, res);
            vec.pop_back();
        }
        generateComb(i + 1, candidates, target, vec, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        generateComb(0, candidates, target, vector<int>(), res);
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "Combinations summing up to " << target << ":\n";
    for(const auto& comb : result)
    {
        cout << "[ ";
        for(int num : comb)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
