#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == 1) 
            {
                count++;
                if(count > maxi)
                    maxi = count;
            }
            else
                count = 0;
        }
        return maxi;
    }
};

int main()
{
    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    Solution sol;
    int maxConsecutiveOnes1 = sol.findMaxConsecutiveOnes(nums1);
    cout << "Maximum consecutive ones in [1, 1, 0, 1, 1, 1]: " << maxConsecutiveOnes1 << endl;

    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    int maxConsecutiveOnes2 = sol.findMaxConsecutiveOnes(nums2);
    cout << "Maximum consecutive ones in [1, 0, 1, 1, 0, 1]: " << maxConsecutiveOnes2 << endl;

    return 0;
}