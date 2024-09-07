#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // VARIETY 1 (IF the no. of positives and negatives are equal)
        // Brute Force Approach (TC: N+N/2 = n, SC: N/2+N/2=N)
        // vector<int> pos;
        // vector<int> neg;
        // for (int i = 0; i < nums.size(); i++) 
        // {
        //     if (nums[i] < 0)
        //         neg.push_back(nums[i]);
        //     else
        //         pos.push_back(nums[i]);
        // }
        // for (int i = 0; i < nums.size() / 2; i++) 
        // {
        //     nums[2 * i] = pos[i];
        //     nums[2 * i + 1] = neg[i];
        // }
        // return nums;

        // Optimal Approach (TC: N, SC: N)
        // int n = nums.size();
        // vector<int> ans(n,0);
        // int posIndex = 0, negIndex = 1;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i] < 0)
        //     {
        //         ans[negIndex] = nums[i];
        //         negIndex+=2;
        //     }
        //     else
        //     {
        //         ans[posIndex] = nums[i];
        //         posIndex+=2;
        //     }
        // }
        // return ans;

        // VARIETY 2 (IF the no. of positives and negatives are not equal)
        // (TC: N+N = 2N, SC: N)
        // vector<int> pos;
        // vector<int> neg;
        // for (int i = 0; i < nums.size(); i++) 
        // {
        //     if (nums[i] < 0)
        //         neg.push_back(nums[i]);
        //     else
        //         pos.push_back(nums[i]);
        // }
        // if(pos.size() > neg.size())
        // {
        //     for(int i = 0; i < neg.size(); i++)
        //     {
        //         nums[2*i] = pos[i];
        //         nums[2*i+1] = neg[i];
        //     }
        //     int index = neg.size()*2;
        //     for(int i = neg.size(); i<pos.size(); i++)
        //     {
        //         nums[index] = pos[i];
        //         index ++;
        //     }
        // }
        // else
        // {
        //     for(int i = 0; i < pos.size(); i++)
        //     {
        //         nums[2*i] = pos[i];
        //         nums[2*i+1] = neg[i];
        //     }
        //     int index = pos.size()*2;
        //     for(int i = pos.size(); i<neg.size(); i++)
        //     {
        //         nums[index] = neg[i];
        //         index ++;
        //     }
        // }
        // return nums;
    }
};

int main() {
    Solution solution;

    // First test case
    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    vector<int> result1 = solution.rearrangeArray(nums1);
    cout << "Rearranged array (test case 1): ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    // Second test case
    vector<int> nums2 = {-1, 1};
    vector<int> result2 = solution.rearrangeArray(nums2);
    cout << "Rearranged array (test case 2): ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}
