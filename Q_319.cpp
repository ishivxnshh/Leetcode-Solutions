#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test Cases
    int n1 = 3;
    cout << "Test Case 1 (n = " << n1 << "): " << sol.bulbSwitch(n1) << endl;

    int n2 = 0;
    cout << "Test Case 2 (n = " << n2 << "): " << sol.bulbSwitch(n2) << endl;

    int n3 = 25;
    cout << "Test Case 3 (n = " << n3 << "): " << sol.bulbSwitch(n3) << endl;

    int n4 = 100;
    cout << "Test Case 4 (n = " << n4 << "): " << sol.bulbSwitch(n4) << endl;

    return 0;
}
