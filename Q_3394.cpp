// Time Complexity: O(n log n) (due to sorting)
// Space Complexity: O(n) (for storing intervals and merged intervals)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<pair<int, int>> buildAndMergeOpen(vector<vector<int>> rectangles, bool vertical)
    {
        vector<pair<int, int>> intervals;
        for (auto rect : rectangles)
        {
            intervals.push_back(vertical ? make_pair(rect[0], rect[2]) : make_pair(rect[1], rect[3]));
        }
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> merged;
        pair<int, int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            pair<int, int> next = intervals[i];
            if (current.second > next.first)
            {
                current.second = max(current.second, next.second);
            }
            else
            {
                merged.push_back(current);
                current = next;
            }
        }
        merged.push_back(current);
        return merged;
    }

    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<pair<int, int>> mergedX = buildAndMergeOpen(rectangles, true);
        if (mergedX.size() >= 3)
        {
            return true;
        }
        vector<pair<int, int>> mergedY = buildAndMergeOpen(rectangles, false);
        if (mergedY.size() >= 3)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> rectangles1 = {{1, 2, 3, 4}, {2, 3, 4, 5}, {5, 6, 7, 8}};
    vector<vector<int>> rectangles2 = {{1, 1, 2, 2}, {2, 2, 3, 3}, {3, 3, 4, 4}};
    
    cout << "Test Case 1: " << (sol.checkValidCuts(rectangles1.size(), rectangles1) ? "Valid" : "Invalid") << endl;
    cout << "Test Case 2: " << (sol.checkValidCuts(rectangles2.size(), rectangles2) ? "Valid" : "Invalid") << endl;
    
    return 0;
}