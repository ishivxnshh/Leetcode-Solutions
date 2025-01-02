#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        
        int i = m - 1;     // Pointer for the last valid element in nums1
        int j = n - 1;     // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the last position in nums1

        // Merge nums1 and nums2 starting from the back
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--]; // Place the larger element in the
                                         // correct position
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy any remaining elements from nums2 into nums1
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    Solution solution;

    // Predefined test case
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    cout << "Before merge:\nNums1: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << "\nNums2: ";
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << "\n";

    // Call the merge function
    solution.merge(nums1, m, nums2, n);

    // Output the merged array
    cout << "After merge:\nNums1: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}