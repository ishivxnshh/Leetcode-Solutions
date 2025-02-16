#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ans = 0;
        while (pq.top() < k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(2 * x + y);
            ans++;
        }
        return ans;
    }
};

// **Driver Code**
int main()
{
    Solution sol;

    // **Sample Test Case 1**
    vector<int> nums1 = {1, 2, 3, 9, 10, 12};
    int k1 = 7;
    cout << "Minimum Operations: " << sol.minOperations(nums1, k1) << endl;
    // Expected Output: 2

    // **Sample Test Case 2**
    vector<int> nums2 = {5, 8, 12, 3, 7};
    int k2 = 15;
    cout << "Minimum Operations: " << sol.minOperations(nums2, k2) << endl;
    // Expected Output: 2

    return 0;
}
