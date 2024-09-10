#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // For std::next_permutation

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // Solution 1 (TLE) (TC: O(nlogn)+O(n⋅n!)+O(n!)=O(n⋅n!), SC: O(n⋅n!))
        // set<vector<int>> permutations; // Set of vectors to store all unique permutations lexicographically
        // vector<int> check = nums;
        // sort(nums.begin(), nums.end()); // Sort the input array
        // do // Generating all permutations
        // {
        //     permutations.insert(nums);
        // } 
        // while (next_permutation(nums.begin(), nums.end()));
        // auto it = permutations.find(check); // To find the current permutation
        // // Moving to the next permutation
        // if (it != permutations.end()) 
        // {
        //     ++it; // Increment the iterator to point to the next permutation
        // }
        // // Handling the last permutation
        // if (it == permutations.end())
        // {
        //     nums = *permutations.begin();  // Cycle back to the first permutation
        // } 
        // else
        // {
        //     nums = *it;  // Set the next permutation
        // }

        // Solution 2 (using STL)
        // next_permutation(nums.begin(), nums.end());

        // Solution 3 (TC: 3N = N, SC: 1)
        int ind = -1;
        int n = nums.size();
        for(int i = n - 2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(int i = n-1;i>ind;i--)
            {
                if(nums[i]>nums[ind])
                {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1, nums.end());
        }
    }
};

// Function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    solution.nextPermutation(nums1);
    cout << "Test Case 1 - Next permutation: ";
    printArray(nums1);

    // Test Case 2
    vector<int> nums2 = {3, 2, 1};
    solution.nextPermutation(nums2);
    cout << "Test Case 2 - Next permutation: ";
    printArray(nums2);

    // Test Case 3
    vector<int> nums3 = {1, 1, 5};
    solution.nextPermutation(nums3);
    cout << "Test Case 3 - Next permutation: ";
    printArray(nums3);

    return 0;
}
