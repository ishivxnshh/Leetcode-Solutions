#include <iostream>
#include <vector>
using namespace std;

// LeetCode-style class solution
class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
    {
        int maxOnes = 0;
        int rowIndex = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            int ones = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    ones++;
                }
            }

            // Update if a new max is found
            if (ones > maxOnes)
            {
                maxOnes = ones;
                rowIndex = i;
            }
        }

        return { rowIndex, maxOnes };
    }
};

// ====================
// 🚀 Driver Code (DC)
// ====================
int main()
{
    Solution solution;

    vector<vector<int>> mat =
    {
        {1, 0, 1},
        {1, 1, 0},
        {0, 0, 1}
    };

    vector<int> result = solution.rowAndMaximumOnes(mat);

    cout << "Row with max 1s: " << result[0] << endl;
    cout << "Number of 1s: " << result[1] << endl;

    return 0;
}