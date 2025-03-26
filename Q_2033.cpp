#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        int remainder = grid[0][0] % x;
        vector<int> vec;
        
        for (auto arr : grid) 
        {
            for (auto num : arr) 
            {
                vec.push_back(num);
                if ((num % x) != remainder) 
                {
                    return -1;
                }
            }
        }

        sort(vec.begin(), vec.end());
        int mid = vec[vec.size() / 2];
        int count = 0;

        for (auto num : vec) 
        {
            count += abs(mid - num) / x;
        }

        return count;
    }
};

// Driver Code
int main() 
{
    Solution solution;
    
    vector<vector<int>> grid1 = {{2, 4}, {6, 8}};
    int x1 = 2;
    cout << "Test Case 1: " << solution.minOperations(grid1, x1) << endl;

    vector<vector<int>> grid2 = {{1, 3}, {5, 7}};
    int x2 = 2;
    cout << "Test Case 2: " << solution.minOperations(grid2, x2) << endl;

    vector<vector<int>> grid3 = {{3, 5}, {7, 9}};
    int x3 = 4;
    cout << "Test Case 3: " << solution.minOperations(grid3, x3) << endl;

    return 0;
}