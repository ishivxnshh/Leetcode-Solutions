#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool daysBtao(vector<int>& weights, int capacity, int days) {
        int count = 1;
        int sum = 0;
        for (auto weight : weights) {
            sum += weight;
            if (sum > capacity) {
                sum = weight;
                count++;
            }
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // O(Nlog(∑weights−max(weights)))
        
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (daysBtao(weights, mid, days)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity required: " << result << endl;

    return 0;
}