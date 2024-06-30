#include <bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                count++;
            }
        } 
        if(count==0 || (count==1 && nums[0]>=nums[nums.size()-1]))
        {
            return true;
        }    
        else    return false;
    }
};
int main()
{
    Solution ob;
    vector<int> nums1={3,4,5,1,2};
    bool res1 = ob.check(nums1);
    cout<<"res1: "<<res1<<endl;
    vector<int> nums2={2,1,3,4};
    bool res2 = ob.check(nums2);
    cout<<"res2: "<<res2<<endl;
    vector<int> nums3={1,2,3};
    bool res3 = ob.check(nums3);
    cout<<"res3: "<<res3<<endl;
}