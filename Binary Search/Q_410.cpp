#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &nums, int pages)
    {
        int stud = 1;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(sum + nums[i] <= pages)
            {
                sum += nums[i];
            }
            else
            {
                stud++;
                sum = nums[i];
            }
        }
        return stud;
    }

    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(countSubarrays(nums, mid) <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Sample test case
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int result = sol.splitArray(nums, k);
    cout << "Minimum largest sum after splitting: " << result << endl;

    return 0;
}