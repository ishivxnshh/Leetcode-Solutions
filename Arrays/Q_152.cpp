#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        // tc: O(2n)
        int maxi = INT_MIN;
        int currentProd = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            currentProd *= nums[i];
            maxi = max(maxi, currentProd);
            if (currentProd == 0)
                currentProd = 1;
        }
        currentProd = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            currentProd *= nums[i];
            maxi = max(maxi, currentProd);
            if (currentProd == 0)
                currentProd = 1;
        }
        return maxi;

        // tc: O(n)
        int maxi = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};

// Driver Code
int main()
{
    Solution obj;
    
    vector<vector<int>> testCases = {
        {2, 3, -2, 4},       // Expected Output: 6
        {-2, 0, -1},         // Expected Output: 0
        {1, 2, 3, 4},        // Expected Output: 24
        {-1, -2, -3, -4},    // Expected Output: 24
        {0, 2, -3, 4, -1},   // Expected Output: 12
        {-2, 3, -4},         // Expected Output: 24
        {0, 0, 0},           // Expected Output: 0
        {1},                 // Expected Output: 1
        {-1},                // Expected Output: -1
        {1, -2, -3, 0, 7, -8, -2} // Expected Output: 112
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << obj.maxProduct(testCases[i]) << endl;
    }

    return 0;
}