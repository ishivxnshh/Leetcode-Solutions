#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Brute Force Approach (TC: N^2, sc: 1) (TLE)
        // int maxprofit = 0;
        // for(int i=0; i<prices.size(); i++) {
        //     for(int j=i+1; j<prices.size(); j++) {
        //         if(prices[j] > prices[i] && prices[j] - prices[i] > maxprofit) {
        //             maxprofit = prices[j] - prices[i];
        //         }
        //     }
        // }   
        // return maxprofit;   

        //Optimal Approach (TC:n, SC: 1)
        int maxprofit = 0, minimum = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int cost = prices[i]-minimum;
            maxprofit = max(maxprofit, cost);
            minimum = min(minimum, prices[i]);
        } 
        return maxprofit;
    }
};

// Driver code
int main() {
    Solution solution;

    // Test Case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit for Test Case 1: " << solution.maxProfit(prices1) << endl;

    // Test Case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit for Test Case 2: " << solution.maxProfit(prices2) << endl;

    return 0;
}
