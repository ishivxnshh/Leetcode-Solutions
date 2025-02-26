#include <iostream>

using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int res = 0;  // XOR identity is 0
        for (int i = 0; i < n; i++)
        {
            res ^= (start + 2 * i);
        }
        return res;
    }
};

// Driver Code
int main()
{
    Solution sol;

    // Test Case 1
    int n1 = 5, start1 = 0;
    cout << "Test Case 1: " << sol.xorOperation(n1, start1) << endl; // Output: 8

    // Test Case 2
    int n2 = 4, start2 = 3;
    cout << "Test Case 2: " << sol.xorOperation(n2, start2) << endl; // Output: 8

    // Test Case 3
    int n3 = 1, start3 = 7;
    cout << "Test Case 3: " << sol.xorOperation(n3, start3) << endl; // Output: 7

    // Test Case 4
    int n4 = 10, start4 = 5;
    cout << "Test Case 4: " << sol.xorOperation(n4, start4) << endl; // Output: 2

    return 0;
}