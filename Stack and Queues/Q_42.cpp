#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
    {
        // Brute-Force Approach (Time Complexity: O(3n), Space Complexity: O(2n))
        // int sum = 0;
        // vector<int> l, r;
        // int lmax = INT_MIN, rmax = INT_MIN;
        // for (int i = 0; i < height.size(); i++)
        // {
        //     lmax = max(lmax, height[i]);
        //     l.push_back(lmax);
        // }
        // for (int i = height.size() - 1; i >= 0; i--)
        // {
        //     rmax = max(rmax, height[i]);
        //     r.push_back(rmax);
        // }
        // reverse(r.begin(), r.end());
        // for (int i = 0; i < height.size(); i++)
        // {
        //     sum += (min(l[i], r[i]) - height[i]);
        // }
        // return sum;

        // Optimal Approach (Time Complexity: O(n), Space Complexity: O(1))
        int lmax = 0, rmax = 0, total = 0, l = 0;
        int r = height.size() - 1;
        while(l < r)
        {
            if(height[l] <= height[r])
            {
                if(lmax > height[l])
                    total += (lmax - height[l]);
                else
                    lmax = height[l];
                l++;
            }
            else
            {
                if(rmax > height[r])
                    total += (rmax - height[r]);
                else
                    rmax = height[r];
                r--;
            }
        }
        return total;
    }    
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = sol.trap(height);
    cout << "Total trapped water: " << result << endl;
    return 0;
}
