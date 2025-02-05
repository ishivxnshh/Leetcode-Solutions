#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countB(vector<int>& bloomDay, int Day, int k) {
        int nOfB = 0;
        int count = 0;
        for (auto it : bloomDay) {
            if (it <= Day) {
                count++;
            } else {
                nOfB += (count / k);
                count = 0;
            }
        }
        nOfB += (count / k);
        return nOfB;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())  
            return -1;  

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());  
        int ans = -1; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int nOfB = countB(bloomDay, mid, k);
            if (nOfB >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    Solution solution;

    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    cout << "Test 1: " << solution.minDays(bloomDay1, m1, k1) << endl;  // Expected: 3

    vector<int> bloomDay2 = {7, 7, 7, 7, 12, 7, 7};
    int m2 = 2, k2 = 3;
    cout << "Test 2: " << solution.minDays(bloomDay2, m2, k2) << endl;  // Expected: 12

    vector<int> bloomDay3 = {1, 10, 3, 10, 2};
    int m3 = 3, k3 = 2;
    cout << "Test 3: " << solution.minDays(bloomDay3, m3, k3) << endl;  // Expected: -1

    return 0;
}