#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double twt = 0;
        int start = customers[0][0];
        for (int i = 0; i < customers.size(); i++)
        {
            if (start < customers[i][0])
            {
                twt += (customers[i][1]);
                start = customers[i][0] + customers[i][1];
                continue;
            }
            twt += (start + customers[i][1] - customers[i][0]);
            start += customers[i][1];
        }
        return twt / customers.size();
    }
};

// **Driver Code**
int main()
{
    Solution sol;
    
    // **Sample Test Case 1**
    vector<vector<int>> customers1 = {{1, 2}, {2, 5}, {4, 3}};
    cout << "Average Waiting Time: " << sol.averageWaitingTime(customers1) << endl; 
    // Expected Output: 5.0

    // **Sample Test Case 2**
    vector<vector<int>> customers2 = {{5, 2}, {6, 3}, {7, 3}, {10, 1}};
    cout << "Average Waiting Time: " << sol.averageWaitingTime(customers2) << endl; 
    // Expected Output: 2.75

    return 0;
}
