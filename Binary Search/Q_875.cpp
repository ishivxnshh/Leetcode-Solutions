#include <iostream>   // For input/output
#include <vector>     // For vector container
#include <algorithm>  // For max_element()
#include <climits>    // For INT_MAX
#include <cmath>      // For ceil()
using namespace std;

class Solution {
public:
    long long timeTaken(vector<int>& piles, int hourly) { 
        long long totalH = 0; 
        for (auto it : piles) {
            totalH += ceil((double)it / hourly);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int left = 1, right = maxi;
        int ans = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;
            long long time = timeTaken(piles, mid);  
            if (time <= h) {
                ans = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    
    // Calling the function and printing the result
    int result = sol.minEatingSpeed(piles, h);
    
    cout << "Minimum eating speed: " << result << endl;
    
    return 0;
}
