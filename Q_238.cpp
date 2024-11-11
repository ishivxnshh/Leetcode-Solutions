#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //Brute Force Approach (TC: n^2, SC: n) (TLE)
        // vector<int> answer;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int mul = 1;
        //     for(int j = 0; j < nums.size(); j++)
        //     {
        //         if(i==j)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             mul*=nums[j];
        //         }
        //     }
        //     answer.push_back(mul);
        // }
        // return answer;

        // Optimized Approach 1(TC: N, SC: N)
        // int n = nums.size();
        // vector<int> preffix(n, 1);
        // vector<int> suffix(n, 1);
        // vector<int> output(n);
        // int prod = 1;
        // for(int i = 0;i<n;i++)
        // {
        //     prod*=nums[i];
        //     preffix[i] = prod;
        // }
        // int prod2 = 1;
        // for(int i = n-1;i>=0;i--)
        // {
        //     prod2*=nums[i];
        //     suffix[i] = prod2;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(i==0)
        //     {
        //         output[i] = suffix[i+1];
        //     }
        //     else if(i==n-1)
        //     {
        //         output[i] = preffix[i-1];
        //     }
        //     else
        //     {
        //         output[i] = preffix[i-1]*suffix[i+1];
        //     }
        // }
        // return output;
                
        // Optimized Approach 2(TC: N, SC: N)
        // int n = nums.size();
        // vector<int> preffix(n, 1);
        // vector<int> output(n);
        // int prod = 1;
        // for(int i = 0;i<n;i++)
        // {
        //     prod*=nums[i];
        //     preffix[i] = prod;
        // }
        // int res=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(i==0)
        //     {
        //         output[i] = res;
        //     }
        //     else if(i==n-1)
        //     {
        //         output[i] = preffix[i-1];
        //     }
        //     else
        //     {
        //         output[i] = preffix[i-1]*res;
        //     }
        //     res*=nums[i];
        // }
        // return output;

        // Optimized Approach 3(TC: N, SC: N)
        int n = nums.size();
        vector<int> output(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= suffix;
            suffix *= nums[i];
        }
        return output;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    
    cout << "Product of array except self for [1, 2, 3, 4]: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    
    cout << "Product of array except self for [-1, 1, 0, -3, 3]: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
