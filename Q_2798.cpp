#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= target)
                cnt++;
        }
        return cnt;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1: General case
    vector<int> hours1 = {5, 8, 6, 7, 10};
    int target1 = 7;
    cout << "Number of employees meeting the target: " 
         << solution.numberOfEmployeesWhoMetTarget(hours1, target1) << endl;

    // Test Case 2: All employees meet the target
    vector<int> hours2 = {9, 10, 12, 8, 7};
    int target2 = 6;
    cout << "Number of employees meeting the target: " 
         << solution.numberOfEmployeesWhoMetTarget(hours2, target2) << endl;

    // Test Case 3: No employees meet the target
    vector<int> hours3 = {3, 2, 1, 4};
    int target3 = 5;
    cout << "Number of employees meeting the target: " 
         << solution.numberOfEmployeesWhoMetTarget(hours3, target3) << endl;

    // Test Case 4: Some employees meet the target
    vector<int> hours4 = {2, 8, 4, 7, 10};
    int target4 = 7;
    cout << "Number of employees meeting the target: " 
         << solution.numberOfEmployeesWhoMetTarget(hours4, target4) << endl;

    return 0;
}
