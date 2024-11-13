#include <iostream>
using namespace std;

// Mock API function to simulate `isBadVersion`
bool isBadVersion(int version) {
    // Set a specific version to be the first bad version for testing
    const int firstBad = 4; // Change this to test with different bad versions
    return version >= firstBad;
}

// Solution class
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

// Driver code
int main() {
    Solution solution;
    int n = 10; // Number of versions, adjust as needed
    cout << "First bad version: " << solution.firstBadVersion(n) << endl;
    return 0;
}