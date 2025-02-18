#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // Brute-Force Appraoch tc(O(k * n))
        // int ans = 1;
        // int i = 0;
        // while (k > 0)
        // {
        //     if (find(arr.begin(), arr.end(), ans) == arr.end())
        //     {
        //         k--;
        //     }
        //     ans++;
        // }
        // return ans - 1;

        // Optimized Approach (tc: logn)
        int left = 0;
            int right = arr.size()-1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                int a = arr[mid] - mid - 1;
                if(a >= k)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return k + right + 1;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << sol.findKthPositive(arr, k) << endl; // Output: 9
    return 0;
}