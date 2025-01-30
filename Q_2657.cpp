#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        // (tc: O(n), sc: O(n))
        int n = A.size();
        vector<int> afreq(n + 1, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            afreq[A[i]]++;
            afreq[B[i]]++;
            if(afreq[A[i]] == 2)
                count++;
            if(afreq[B[i]] == 2 && A[i] != B[i])
                count++;

            A[i] = count;
        }
        return A;
    }
};

int main() {
    Solution solution;
    
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    
    vector<int> result = solution.findThePrefixCommonArray(A, B);
    
    cout << "Result: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    // Sample test case 2
    vector<int> A2 = {1, 5, 4, 3, 2};
    vector<int> B2 = {3, 1, 2, 4, 5};
    
    result = solution.findThePrefixCommonArray(A2, B2);
    
    cout << "Result: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
