#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> hash(n * n + 1, 0);
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                hash[grid[i][j]]++;
            }
        }
        
        int a = -1;
        int b = -1;
        
        for (int i = 1; i <= n * n; i++) 
        {
            if (a == -1 || b == -1) 
            {
                if (hash[i] == 0)
                {
                    b = i;
                }
                else if (hash[i] > 1)
                {
                    a = i;
                }
            }
            else
            {
                break;
            }
        }
        return {a, b};
    }
};

// Driver Code
int main() 
{
    Solution sol;
    
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    vector<vector<int>> grid2 = {{4, 2, 1}, {6, 5, 3}, {9, 8, 7}};
    
    vector<int> result1 = sol.findMissingAndRepeatedValues(grid1);
    cout << "Repeated: " << result1[0] << ", Missing: " << result1[1] << endl;

    vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Repeated: " << result2[0] << ", Missing: " << result2[1] << endl;

    return 0;
}