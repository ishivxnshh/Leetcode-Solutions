// Time Complexity: O(n log n) due to map operations.
// Space Complexity: O(n) for storing elements in the map.

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        int count = 0;
        for (auto it = mpp.rbegin(); it != mpp.rend(); it++)
        {
            count += it->second;
            if (count >= k)
            {
                return it->first;
            }
        }
        return -1;
    }
};

// Driver Code
int main() 
{
    Solution obj;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    int result = obj.findKthLargest(nums, k);
    
    cout << "The " << k << "th largest element is: " << result << endl;
    
    return 0;
}
