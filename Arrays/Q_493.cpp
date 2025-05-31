#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Count reverse pairs across the two sorted halves
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (j <= high && (long long)arr[i] > 2LL * arr[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }

        return count;
    }

    // Merge two sorted subarrays: arr[low..mid] and arr[mid+1..high]
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }

        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    // Divide and conquer with counting and merging
    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
        {
            return 0;
        }

        int mid = (low + high) / 2;
        int count = 0;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return count;
    }

    // Main function to call
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

// =======================
// ✅ Driver Code
// =======================
int main()
{
    Solution sol;

    vector<int> nums1 = {1, 3, 2, 3, 1};
    vector<int> nums2 = {2, 4, 3, 5, 1};

    cout << "Reverse Pairs in nums1: " << sol.reversePairs(nums1) << endl;
    cout << "Reverse Pairs in nums2: " << sol.reversePairs(nums2) << endl;

    return 0;
}