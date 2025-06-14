#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // Brute-Force Approach (Time Complexity: O(m * n), Space Complexity: O(1))
        // for (int i = 0; i < nums1.size(); i++)
        // {
        //     int check = 0;
        //     int flag = -1;
        //     for (int j = 0; j < nums2.size(); j++)
        //     {
        //         if (nums1[i] == nums2[j])
        //         {
        //             check = 1;
        //         }
        //         if (check == 1 && nums2[j] > nums1[i])
        //         {
        //             flag = nums2[j];
        //             break;
        //         }
        //     }
        //     nums1[i] = flag;
        // }
        // return nums1;

        // Stack Based Approach 
        // Time Complexity: O(n + n + m), where n = nums1.size(), m = nums2.size()
        // Space Complexity: O(m) for the stack and hashmap
        stack<int> stk;
        unordered_map<int, int> mpp;
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            while(!stk.empty() && stk.top() <= nums2[i])
            {
                stk.pop();
            }
            if(stk.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = mpp[nums1[i]];
        }
        return nums1;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = obj.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}