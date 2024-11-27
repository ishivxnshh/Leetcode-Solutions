#include <iostream>
using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        if (n == 1)
            return 1;
        else
            return n - 1;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int n1 = 5;
    cout << "Test Case 1 - Input: " << n1 << ", Output: " << sol.distinctIntegers(n1) << ", Expected: 4" << endl;

    // Test Case 2
    int n2 = 3;
    cout << "Test Case 2 - Input: " << n2 << ", Output: " << sol.distinctIntegers(n2) << ", Expected: 2" << endl;

    return 0;
}
