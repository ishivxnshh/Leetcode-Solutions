#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        int answer1 = 0;
        int answer2 = 0;
        
        for (auto& num : nums1) {
            if (set2.find(num) != set2.end())
                answer1++;
        }
        
        for (auto& num : nums2) {
            if (set1.find(num) != set1.end())
                answer2++;
        }
        
        return {answer1, answer2};
    }
};

int main() {
    Solution sol;

    // Test case 1
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> result = sol.findIntersectionValues(nums1, nums2);
    std::cout << "Test case 1 result: [" << result[0] << ", " << result[1] << "]\n";

    // Test case 2
    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    result = sol.findIntersectionValues(nums1, nums2);
    std::cout << "Test case 2 result: [" << result[0] << ", " << result[1] << "]\n";

    return 0;
}
