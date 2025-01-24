#include <iostream>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};

int main() {
    Solution solution;
    
    // Test Cases (TCS)
    int testCases[][2] = {
        {3, 2},  // Example 1: num = 3, t = 2
        {5, 4},  // Example 2: num = 5, t = 4
        {0, 0},  // Edge Case: num = 0, t = 0
        {-1, 2}, // Edge Case: num = -1, t = 2
        {10, 0}, // Edge Case: num = 10, t = 0
    };

    int numberOfTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numberOfTestCases; ++i) {
        int num = testCases[i][0];
        int t = testCases[i][1];
        cout << "Test Case " << i + 1 << ": num = " << num << ", t = " << t
             << " => Maximum Achievable X = " << solution.theMaximumAchievableX(num, t) << endl;
    }

    return 0;
}
