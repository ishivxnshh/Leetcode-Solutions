#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        deque<int> que;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!que.empty() && que.front() <= i - k)
            {
                que.pop_front();
            }

            while (!que.empty() && nums[que.back()] <= nums[i])
            {
                que.pop_back();
            }

            que.push_back(i);

            if (i >= k - 1)
            {
                ans.push_back(nums[que.front()]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Output: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}