#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        //Brute Force Approach(tc:O(n^2), sc:O(n))
        vector<int> ans;
        for (int i = 0; i < boxes.length(); i++) 
        {
            int count = 0;
            for (int j = 0; j < boxes.length(); j++) 
            {
                if (boxes[j] == '1')
                    count += abs(j - i);
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};

// Driver Code
int main() 
{
    Solution solution;

    // Test Case 1
    string boxes1 = "110";
    vector<int> result1 = solution.minOperations(boxes1);
    cout << "Operations needed for boxes1: ";
    for (int num : result1) 
        cout << num << " ";
    cout << endl;

    // Test Case 2
    string boxes2 = "001011";
    vector<int> result2 = solution.minOperations(boxes2);
    cout << "Operations needed for boxes2: ";
    for (int num : result2) 
        cout << num << " ";
    cout << endl;

    // Test Case 3
    string boxes3 = "000";
    vector<int> result3 = solution.minOperations(boxes3);
    cout << "Operations needed for boxes3: ";
    for (int num : result3) 
        cout << num << " ";
    cout << endl;

    return 0;
}