#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int count = 0;
        for (int i = 0; i < seats.size(); i++) 
        {
            count += abs(seats[i] - students[i]);
        }
        return count;
    }
};

// Driver Code
int main() 
{
    Solution solution;

    // Test Case 1
    vector<int> seats1 = {3, 1, 5};
    vector<int> students1 = {2, 7, 4};
    cout << "Minimum moves (Test 1): " << solution.minMovesToSeat(seats1, students1) << endl;

    // Test Case 2
    vector<int> seats2 = {4, 1, 5, 9};
    vector<int> students2 = {1, 3, 2, 6};
    cout << "Minimum moves (Test 2): " << solution.minMovesToSeat(seats2, students2) << endl;

    // Test Case 3
    vector<int> seats3 = {2, 2, 6, 6};
    vector<int> students3 = {1, 3, 2, 6};
    cout << "Minimum moves (Test 3): " << solution.minMovesToSeat(seats3, students3) << endl;

    return 0;
}
