#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 1;
        int right = numbers.size();

        while (left - 1 < right - 1)
        {
            int sum = numbers[left - 1] + numbers[right - 1];

            if (sum == target)
            {
                return {left, right};
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {-1, -1};  // No valid pair found
    }
};

// Driver Code
int main() 
{
    Solution obj;

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = obj.twoSum(numbers, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}