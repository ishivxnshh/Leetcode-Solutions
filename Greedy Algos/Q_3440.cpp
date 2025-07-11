#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        vector<int> freeGaps(1, startTime[0]);

        for (int i = 1; i < startTime.size(); i++)
        {
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }

        freeGaps.push_back(eventTime - endTime.back());

        vector<int> largestLeft(freeGaps.size(), 0);
        for (int i = 2; i < freeGaps.size(); i++)
        {
            largestLeft[i] = max(largestLeft[i - 1], freeGaps[i - 2]);
        }

        vector<int> largestRight(freeGaps.size(), 0);
        for (int i = freeGaps.size() - 2; i >= 0; i--)
        {
            largestRight[i] = max(largestRight[i + 1], freeGaps[i + 1]);
        }

        int maxFreeDuration = 0;

        for (int i = 1; i < freeGaps.size(); i++)
        {
            int meetingTime = endTime[i - 1] - startTime[i - 1];

            if (meetingTime <= max(largestLeft[i], largestRight[i]))
            {
                maxFreeDuration = max(maxFreeDuration, freeGaps[i - 1] + freeGaps[i] + meetingTime);
            }

            maxFreeDuration = max(maxFreeDuration, freeGaps[i - 1] + freeGaps[i]);
        }

        return maxFreeDuration;
    }
};

int main()
{
    Solution obj;

    // Sample Input
    int eventTime = 20;
    vector<int> startTime = {2, 6, 10};
    vector<int> endTime = {4, 8, 12};

    // Function Call
    int result = obj.maxFreeTime(eventTime, startTime, endTime);

    // Output Result
    cout << "Maximum Free Time: " << result << endl;

    return 0;
}