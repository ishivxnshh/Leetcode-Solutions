#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k % n;

        //Approach-1
        // vector<int> temp(k);
        // for(int i=n-k;i<n;i++)
        // {
        //     temp[i-(n-k)] = nums[i];
        // }
        // for(int i=n-k-1;i>=0;i--)
        // {
        //     nums[i+k] = nums[i];
        // }
        // for(int i=0;i<k;i++)
        // {
        //     nums[i] = temp[i];
        // }
        
        //Approach-2
        // vector<int> temp(n);
        // for(int i=0;i<n;i++)
        // {
        //     temp[(i+k)%n]=nums[i];
        // }
        // nums=temp;

        //Approach-3
        // reverse(nums.begin(), nums.end()-k);
        // reverse(nums.end()-k, nums.end());
        // reverse(nums.begin(), nums.end());
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
