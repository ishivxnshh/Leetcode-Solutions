#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = -9999;  // Initialize maxi to a low value
        for(int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for(int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

int main() {
    // Test case
    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 5, 6}
    };

    Solution solution;
    int result = solution.maximumWealth(accounts);
    
    cout << "Maximum wealth: " << result << endl;

    return 0;
}