#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end()); // Sort by start day

        int i = 0;
        int day = events[0][0];
        int res = 0;
        int n = events.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;

        while (!minHeap.empty() || i < n)
        {
            if (minHeap.empty())
            {
                day = events[i][0];
            }

            while (i < n && events[i][0] == day)
            {
                minHeap.push(events[i][1]); // Push end day
                i++;
            }

            if (!minHeap.empty())
            {
                minHeap.pop();
                res++;
            }

            day++;

            while (!minHeap.empty() && minHeap.top() < day)
            {
                minHeap.pop();
            }
        }

        return res;
    }
};

// 🧪 Driver Code
int main()
{
    Solution sol;

    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    int maxAttended = sol.maxEvents(events);

    cout << "Maximum number of events that can be attended: " << maxAttended << endl;

    return 0;
}