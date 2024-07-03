#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // //Brute Force Approach
        // vector<int> temp;
        // //copy non-zero elements
        // //from original -> temp array:
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] != 0)
        //         temp.push_back(nums[i]);
        // }

        // // number of non-zero elements.
        // int nz = temp.size();

        // //copy elements from temp
        // //fill first nz fields of
        // //original array:
        // for (int i = 0; i < nz; i++) {
        //     nums[i] = temp[i];
        // }
        
        // //fill rest of the cells with 0:
        // for (int i = nz; i < n; i++) {
        //     nums[i] = 0;
        // }


        //Optimal approach
        // int l = 0;
        // for(int j=0;j<n;j++)
        // {
        //     if(nums[j]!=0)
        //     {
        //         swap(nums[j], nums[l]);
        //         l++;
        //     }
        // }        
    }
};
int main()
{
    Solution ob;
    vector<int> arr = {0,1,0,3,12};
    int n = 10;
    ob.moveZeroes(arr);
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}