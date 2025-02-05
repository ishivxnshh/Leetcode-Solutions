#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int count = 0;
        vector<int> gaps(1, startTime[0]);
        for(int i=1;i<startTime.size();i++)
        {
            gaps.push_back(startTime[i] - endTime[i-1]);
        }
        gaps.push_back(eventTime - endTime.back());
        
        int maxDuration = 0, currentSum = 0;
        //sliding window of k+1 as k meetings so k+1 gaps
        for(int i=0;i<gaps.size();i++)
        {
            currentSum += gaps[i];
            if(i > k)
                currentSum -= gaps[i - (k + 1)];
            maxDuration = max(maxDuration, currentSum);
        }
        return maxDuration;
    }
};

// Driver Code
int main() {
    Solution solution;
    
    // Test Case 1
    int eventTime1 = 10, k1 = 1;
    vector<int> startTime1 = {1, 3, 6};
    vector<int> endTime1 = {2, 5, 8};
    cout << "Max Free Time (Test 1): " << solution.maxFreeTime(eventTime1, k1, startTime1, endTime1) << endl;

    // Test Case 2
    int eventTime2 = 15, k2 = 2;
    vector<int> startTime2 = {2, 5, 9, 12};
    vector<int> endTime2 = {4, 7, 10, 14};
    cout << "Max Free Time (Test 2): " << solution.maxFreeTime(eventTime2, k2, startTime2, endTime2) << endl;

    return 0;
}
