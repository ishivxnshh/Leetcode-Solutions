#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        long long m_sum = 0;
        int count = 0;
        int least = INT_MAX;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                m_sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) count++;
                if (abs(matrix[i][j]) < least) least = abs(matrix[i][j]);
            }
        }

        if (count % 2 == 0)
            return m_sum;
        else
            return m_sum - 2 * least;
    }
};

int main()
{
    Solution obj;

    vector<vector<vector<int>>> testCases = {
        {{1, 2}, {3, 4}},                         // Test 1
        {{1, -2, 3}, {-4, 5, -6}, {7, -8, 9}},    // Test 2
        {{-1, 2}, {3, 4}},                        // Test 3
        {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}}, // Test 4
        {{0, -1}, {2, 3}},                        // Test 5
        {{-5}},                                  // Test 6
        {{100000, -100000}, {-100000, 100000}}   // Test 7
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << " Output: "
             << obj.maxMatrixSum(testCases[i]) << endl;
    }

    return 0;
}
