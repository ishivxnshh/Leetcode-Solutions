#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int res = 0;

        while (j < nums.size())
        {
            mpp[nums[j]]++;

            while (mpp.size() == st.size())
            {
                res += (nums.size() - j);
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return res;
    }
};

// Driver code
int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 1, 2, 2};  // Sample test case
    int result = sol.countCompleteSubarrays(nums);
    
    cout << "Count of complete subarrays: " << result << endl;

    return 0;
}