#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long ColoredCells = 1;
        for(int i = 1; i < n; i++)
            ColoredCells += 4 * i;
        return ColoredCells;

        // 
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test Case 1
    int n1 = 1;
    cout << "Colored Cells (Test Case 1): " << sol.coloredCells(n1) << endl;  // Expected: 1

    // Test Case 2
    int n2 = 2;
    cout << "Colored Cells (Test Case 2): " << sol.coloredCells(n2) << endl;  // Expected: 5

    // Test Case 3
    int n3 = 3;
    cout << "Colored Cells (Test Case 3): " << sol.coloredCells(n3) << endl;  // Expected: 13

    // Test Case 4
    int n4 = 4;
    cout << "Colored Cells (Test Case 4): " << sol.coloredCells(n4) << endl;  // Expected: 25

    return 0;
}