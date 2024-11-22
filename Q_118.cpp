#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int i = 0;
        while (i < numRows) {
            vector<int> vec;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    vec.push_back(1);
                else
                    vec.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res.push_back(vec);
            i++;
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Input number of rows
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    // Generate Pascal's Triangle
    vector<vector<int>> result = solution.generate(numRows);

    // Print the result
    cout << "Pascal's Triangle:\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}