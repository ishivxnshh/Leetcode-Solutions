#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++) 
        {
            int num = nums[i];

            if (mpp.find(num) != mpp.end())
                res = min(res, i - mpp[num]);

            int temp = num;
            int rev = 0;

            if (temp == 0) rev = 0;

            while (temp) 
            {
                rev = rev * 10 + temp % 10;
                temp /= 10;
            }

            if (mpp.find(rev) == mpp.end()) 
            {
                mpp[rev] = i;
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};

int main() 
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.minMirrorPairDistance(nums);

    cout << "Minimum Mirror Pair Distance: " << result << endl;

    return 0;
}