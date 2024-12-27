#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        // Brute-Force Approach(tc: O(nlogn + n^2)=O(n^2), sc: O(n))
        //precise tc analysis(tc: O(nlogn + 2n)=O(nlogn))
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> result;
        // for (int i = 0; i < intervals.size(); i++)
        // {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if (!result.empty() && result.back()[1] >= end)
        //     {
        //         continue;
        //     }
        //     for (int j = i + 1; j < intervals.size(); j++)
        //     {
        //         if (intervals[j][0] <= end)
        //             end = max(end, intervals[j][1]);
        //         else
        //             break;
        //     }
        //     result.push_back({start, end});
        // }
        // return result;

        // Better-Approach(tc: O(nlogn + n)=O(nlogn), sc: O(n))
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) 
        {
            if (intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start, end});
        return result;
    }
};

int main()
{
    Solution solution;

    // Predefined test cases
    vector<vector<int>> testCase1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> testCase2 = {{1, 4}, {4, 5}};

    // Test case 1
    cout << "Test Case 1:\n";
    vector<vector<int>> result1 = solution.merge(testCase1);
    for (const auto &interval : result1)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    // Test case 2
    cout << "Test Case 2:\n";
    vector<vector<int>> result2 = solution.merge(testCase2);
    for (const auto &interval : result2)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
