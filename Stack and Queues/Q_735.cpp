#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                stk.push(asteroids[i]);
            } else {
                while (!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i]))
                    stk.pop();
                if (!stk.empty() && stk.top() == abs(asteroids[i]))
                    stk.pop();
                else if (stk.empty() || stk.top() < 0)
                    stk.push(asteroids[i]);
            }
        }
        vector<int> res(stk.size());
        int i = stk.size() - 1;
        while (!stk.empty()) {
            res[i--] = stk.top();
            stk.pop();
        }
        return res;
    }
};

// ----------------------- Driver Code -----------------------
int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {-2, -1, 1, 2},
        {5, 10, -5, -11},
        {1, -1, 1, -1, 1}
    };

    for (int t = 0; t < testCases.size(); ++t) {
        vector<int> input = testCases[t];
        vector<int> result = sol.asteroidCollision(input);
        cout << "Test Case " << t + 1 << ": ";
        for (int x : result)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}