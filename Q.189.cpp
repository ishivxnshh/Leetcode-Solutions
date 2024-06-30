#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums=temp;
    }
};

int main()
{
    Solution ob;
    vector<int> nums{1,2,3,4,5,6,7,8};
    int k = 3;
    ob.rotate(nums, k);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}
