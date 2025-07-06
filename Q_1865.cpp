#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            ++cnt[num];
        }
    }
    
    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }
    
    int count(int tot) {  
        int ans = 0;
        for (int num : nums1) {
            if (cnt.count(tot - num)) {
                ans += cnt[tot - num];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4};

    FindSumPairs* obj = new FindSumPairs(nums1, nums2);

    cout << "Count(5): " << obj->count(5) << endl;  // Expecting 2 (1+4 and 2+3)

    obj->add(0, 1);  // nums2 becomes {4, 4}

    cout << "Count(5): " << obj->count(5) << endl;  // Expecting 1 (1+4)

    obj->add(1, 1);  // nums2 becomes {4, 5}

    cout << "Count(6): " << obj->count(6) << endl;  // Expecting 2 (1+5 and 2+4)

    delete obj;
    return 0;
}