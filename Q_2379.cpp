#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class definition
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int l = 0, r = 0;
        int mini = k;
        
        while (l <= blocks.length() - k && r < blocks.length()) 
        {
            if (blocks[r] == 'W')
                count++;
            if ((r - l + 1) == k) 
            {
                mini = min(mini, count);
                if (blocks[l] == 'W')
                    count--;
                l++;
            }
            r++;
        }
        return mini;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Sample Test Cases
    vector<pair<string, int>> testCases = {
        {"WBBWWBBWBW", 3},  // Expected output: 1
        {"BBBBBB", 3},      // Expected output: 0
        {"WWWW", 2},        // Expected output: 2
        {"WBWBWBWB", 4},    // Expected output: 2
        {"WWBWWBW", 3}      // Expected output: 1
    };

    for (auto& test : testCases) {
        cout << "Input: blocks = \"" << test.first << "\", k = " << test.second << endl;
        cout << "Output: " << sol.minimumRecolors(test.first, test.second) << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}