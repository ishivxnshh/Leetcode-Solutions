#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        /*
            Brute-Force Approach
            Time Complexity: O(n + k), where n is the size of arr and k is the number of unique elements in arr.
            Space Complexity: O(k), for storing the frequency map.
        */
        // map<int, int> freqMap;
        // for (int i = 0; i < arr.size(); i++) {
        //     freqMap[arr[i]]++;            
        // }
        // int res = -1;
        // for (auto it : freqMap) {
        //     if(it.first == it.second && it.first > res)
        //         res = it.first;
        // }
        // return res;

        /*
            Better Approach
            Time Complexity: O(n), where n is the size of arr.
            Space Complexity: O(1), since the frequency array size is constant (501).
        */
        // int freqMap[501] = {};
        // for (int i = 0; i < arr.size(); i++)
        // {
        //     freqMap[arr[i]]++;            
        // }
        // int res = -1;
        // for (int i = 1; i < 500; i++)
        // {
        //     if(i == freqMap[i])
        //         res = i;
        // }
        // return res;

        /*
            Optimal Approach
            Time Complexity: O(n), where n is the size of arr.
            Space Complexity: O(1), since the algorithm modifies the input array in-place and does not use extra space proportional to input size.
        */
        int n = arr.size();
        // Clear upper 16 bits in case the array was reused
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] & 65535;
        }
        // Encode frequency in upper 16 bits
        for (int &num : arr) {
            int val = (num & 65535);
            if (val <= n) {
                arr[val - 1] += (1 << 16);
            }
        }
        // Check from high to low for lucky number
        for (int val = n; val >= 1; val--) {
            if ((arr[val - 1] >> 16) == val) {
                return val;
            }   
        }
        return -1;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Sample test case
    vector<int> arr = {2, 2, 3, 4};
    
    int result = sol.findLucky(arr);
    cout << "The lucky number is: " << result << endl;

    return 0;
}