#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxElement(vector<vector<int>> mat, int mid, int n)
    {
        int maxi = mat[0][mid];
        int ind = 0;
        for (int i = 1; i < n; i++)
        {
            if (mat[i][mid] > maxi)
            {
                maxi = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        // Brute-Force Approach(iterating over all the elements) (tc: O(m*n), sc: O(1))

        // Optimal Approach (tc: O(nlogm), sc: O(1))
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int maxRowIndex = maxElement(mat, mid, n);

            int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;
            int maxEleMid = mat[maxRowIndex][mid];

            if (maxEleMid > left && maxEleMid > right)
            {
                return {maxRowIndex, mid};
            }
            else if (left > maxEleMid)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> mat1 = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<vector<int>> mat2 = {
        {1, 4},
        {3, 2}
    };

    vector<int> peak1 = sol.findPeakGrid(mat1);
    vector<int> peak2 = sol.findPeakGrid(mat2);

    cout << "Test Case 1 Peak at: [" << peak1[0] << ", " << peak1[1] << "]" << endl;
    cout << "Test Case 2 Peak at: [" << peak2[0] << ", " << peak2[1] << "]" << endl;

    return 0;
}
