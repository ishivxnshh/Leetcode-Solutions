#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    typedef pair<int, int> P;

    int countWalls(vector<int> &walls, int l, int r)
    {
        int left = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;
    }

    int solve(vector<int> &walls, vector<P> &robotDist, vector<P> &range, int i, int dir, vector<vector<int>> &t)
    {
        if (i == robotDist.size()) return 0;

        if (t[i][dir] != -1) return t[i][dir];

        int leftStart = range[i].first;

        if (dir == 1 && i > 0)
        {
            leftStart = max(leftStart, range[i - 1].second + 1);
        }

        int leftTake = countWalls(walls, leftStart, robotDist[i].first)
                       + solve(walls, robotDist, range, i + 1, 0, t);
        
        int rightTake = countWalls(walls, robotDist[i].first, range[i].second)
                        + solve(walls, robotDist, range, i + 1, 1, t);

        return t[i][dir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) 
    {
        int n = robots.size();
        
        vector<P> robotDist(n);

        for (int i = 0; i < n; i++)
        {
            robotDist[i] = {robots[i], distance[i]};
        }

        sort(begin(robotDist), end(robotDist));
        sort(begin(walls), end(walls));

        vector<P> range(n);

        for (int i = 0; i < n; i++)
        {
            int pos = robotDist[i].first;
            int d = robotDist[i].second;

            int leftlimit = (i == 0) ? 1 : robotDist[i - 1].first + 1;
            int rightlimit = (i == n - 1) ? 1e9 : robotDist[i + 1].first - 1;

            int L = max(pos - d, leftlimit);
            int R = min(pos + d, rightlimit);

            range[i] = {L, R};
        }

        vector<vector<int>> t(n, vector<int>(2, -1));

        return solve(walls, robotDist, range, 0, 0, t);
    }
};

int main()
{
    Solution obj;

    vector<int> robots = {3, 8, 15};
    vector<int> distance = {2, 3, 5};
    vector<int> walls = {1, 4, 6, 10, 12, 14};

    int result = obj.maxWalls(robots, distance, walls);

    cout << "Maximum walls destroyed: " << result << endl;

    return 0;
}