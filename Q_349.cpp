#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        int i = 0, j = 0;
        int lastele = -99; // Assuming -99 is not a valid element in nums1 or nums2
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums2[j] < nums1[i]) {
                j++;
            } else { // nums1[i] == nums2[j]
                if (nums1[i] != lastele) {
                    ans.push_back(nums1[i]);
                    lastele = nums1[i];
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> result = solution.intersection(nums1, nums2);
    
    // Print the result
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
