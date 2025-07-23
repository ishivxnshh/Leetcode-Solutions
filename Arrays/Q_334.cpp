#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        // (tc: O(n), sc: O(1))
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto num : nums)
        {
            if (num <= first) first = num;
            else if (num <= second) second = num;
            else return true;
        }
        return false;
    }
};

// Driver Code
int main() 
{
    Solution solution;
    
    vector<int> nums1 = {2, 1, 5, 0, 4, 6};
    cout << "Test Case 1: " << (solution.increasingTriplet(nums1) ? "True" : "False") << endl;

    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Test Case 2: " << (solution.increasingTriplet(nums2) ? "True" : "False") << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3: " << (solution.increasingTriplet(nums3) ? "True" : "False") << endl;

    return 0;
}
