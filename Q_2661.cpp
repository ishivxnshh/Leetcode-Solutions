#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        // Brute-Force Approach (TLE: 1055/1058) (TC: O(n⋅m⋅p⋅(m+p))=O(n⋅m⋅p⋅max(m,p)), sc:1)
        // for (int i = 0; i < arr.size(); i++) 
        // {
        //     for (int j = 0; j < mat.size(); j++) 
        //     {
        //         for (int k = 0; k < mat[0].size(); k++) 
        //         {
        //             if (mat[j][k] == arr[i]) 
        //             {
        //                 mat[j][k] = -999;
        //                 int flag = 0;
        //                 for (int l = 0; l < mat[0].size(); l++) 
        //                 {
        //                     if (mat[j][l] != -999) 
        //                     {
        //                         flag = 1;
        //                         break;
        //                     }
        //                 }
        //                 if (flag == 0)
        //                     return i;
        //                 flag = 0;
        //                 for (int l = 0; l < mat.size(); l++) 
        //                 {
        //                     if (mat[l][k] != -999) 
        //                     {
        //                         flag = 1;
        //                         break;
        //                     }
        //                 }
        //                 if (flag == 0)
        //                     return i;
        //             }
        //         }
        //     }
        // }
        // return -1;

        // more-optimised(TC:O(m⋅n+m+n+a)=O(m.n+a), SC:O(m⋅n+m+n))
    }
};

int main() 
{
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 3, 4, 2};
    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    cout << "Test Case 1 - Output: " << sol.firstCompleteIndex(arr1, mat1) << ", Expected: 2" << endl;

    // Test Case 2
    vector<int> arr2 = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat2 = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << "Test Case 2 - Output: " << sol.firstCompleteIndex(arr2, mat2) << ", Expected: 8" << endl;

    return 0;
}
