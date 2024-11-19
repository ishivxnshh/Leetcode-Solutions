#include <iostream>
#include <vector>
using namespace std;

// The Solution class with the setZeroes function
class Solution
{
public:
    // Brute-Force Approach [Wrong Answer: 200/202 TCs Passed] (TC: O(m*n*(m+n)) + O(m*n), SC: 1)
    //      void setZeroes(vector<vector<int>>& matrix) {
    //          for (int i = 0; i < matrix.size(); i++) {
    //              for (int j = 0; j < matrix[i].size(); j++) {
    //                  if (matrix[i][j] == 0) {
    //                      markRow(i, matrix);
    //                      markColumn(j, matrix);
    //                  }
    //              }
    //          }
    //          for (int i = 0; i < matrix.size(); i++) {
    //              for (int j = 0; j < matrix[i].size(); j++) {
    //                  if (matrix[i][j] == -1) {
    //                      matrix[i][j] = 0;
    //                  }
    //              }
    //          }
    //      }

    //     void markRow(int i, vector<vector<int>>& matrix) {
    //         for (int j = 0; j < matrix[i].size(); j++) {
    //             if (matrix[i][j] != 0)
    //                 matrix[i][j] = -1;
    //         }
    //     }

    //     void markColumn(int j, vector<vector<int>>& matrix) {
    //         for (int i = 0; i < matrix.size(); i++) {
    //             if (matrix[i][j] != 0)
    //                 matrix[i][j] = -1;
    //         }
    //     }
    // };

    void setZeroes(vector<vector<int>> &matrix)
    {
        // better Approach (TC: 2*m*n, SC: m+n)
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<int> row(m,0);
        // vector<int> column(n,0);
        // for(int i = 0; i < m; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(matrix[i][j]==0)
        //         {
        //             row[i] = 1;
        //             column[j] = 1;
        //         }
        //     }
        // }
        // for(int i = 0; i < m; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(row[i]==1 || column[j]==1)
        //         {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        //Optimized Approach (TC: 2*m*n, SC: 1)

        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    if(j!=0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]!=0)
                {
                    if(matrix[i][0]==0 || matrix[0][j]==0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int j=1;j<n;j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(col0==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }

    // Function to print a matrix
    void printMatrix(const vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (const auto &elem : row)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    int main()
    {
        Solution sol;

        // Test Case 1
        vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 0, 6},
            {7, 8, 9}};
        cout << "Original Matrix (Test Case 1):" << endl;
        printMatrix(matrix1);

        sol.setZeroes(matrix1);

        cout << "Modified Matrix (Test Case 1):" << endl;
        printMatrix(matrix1);

        // Test Case 2
        vector<vector<int>> matrix2 = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}};
        cout << "\nOriginal Matrix (Test Case 2):" << endl;
        printMatrix(matrix2);

        sol.setZeroes(matrix2);

        cout << "Modified Matrix (Test Case 2):" << endl;
        printMatrix(matrix2);

        return 0;
    }
};