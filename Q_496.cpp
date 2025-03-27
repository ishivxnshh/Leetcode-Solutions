#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            int check = 0;
            int flag = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    check = 1;
                }
                if (check == 1 && nums2[j] > nums1[i])
                {
                    flag = nums2[j];
                    break;
                }
            }
            nums1[i] = flag;
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