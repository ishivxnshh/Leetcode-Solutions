#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            count += mpp[nums[i]];
            mpp[nums[i]]++;
        }
        return count;
    }
};

// Driver Code
int main()
{
    Solution solution;
    vector<vector<int>> testCases = {
        {1, 2, 3, 1, 1, 3},  // Expected output: 4
        {1, 1, 1, 1},        // Expected output: 6
        {1, 2, 3},           // Expected output: 0
        {2, 2, 2, 2, 2},     // Expected output: 10
        {1, 2, 1, 2, 1}      // Expected output: 4
    };

    for (auto &test : testCases)
    {
        cout << "Input: { ";
        for (int num : test)
        {
            cout << num << " ";
        }
        cout << "} -> Number of good pairs: " << solution.numIdenticalPairs(test) << endl;
    }

    return 0;
}