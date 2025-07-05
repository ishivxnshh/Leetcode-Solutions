#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void generateKro(int i, vector<int>& vec, vector<int> temp, vector< vector<int>>& res, int k, int n)
    {
        if (n < 0)
            return;

        if (temp.size() == k)
        {
            if (n == 0)
                res.push_back(temp);
            return;
        }

        if (i == 9)
            return;

        temp.push_back(vec[i]);
        generateKro(i + 1, vec, temp, res, k, n - vec[i]);
        temp.pop_back();
        generateKro(i + 1, vec, temp, res, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector< vector<int>> res;
        vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        generateKro(0, vec, vector<int>(), res, k, n);
        return res;
    }
};

// Driver code
int main()
{
    Solution obj;

    int k = 3;
    int n = 7;

    vector<vector<int>> result = obj.combinationSum3(k, n);

    cout << "Combinations of " << k << " numbers that sum to " << n << ":\n";
    for (const auto& combination : result)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}