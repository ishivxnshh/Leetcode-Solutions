#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int track = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > track) {
                int temp = track;
                track = arr[i];
                arr[i] = temp;
            } else {
                arr[i] = track;
            }
        }
        arr[n - 1] = -1;
        return arr;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1: General case
    vector<int> arr1 = {17, 18, 5, 4, 6, 1};
    vector<int> result1 = solution.replaceElements(arr1);
    cout << "Replaced array: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2: Single element
    vector<int> arr2 = {5};
    vector<int> result2 = solution.replaceElements(arr2);
    cout << "Replaced array: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 3: Already sorted in descending order
    vector<int> arr3 = {10, 9, 8, 7, 6};
    vector<int> result3 = solution.replaceElements(arr3);
    cout << "Replaced array: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
