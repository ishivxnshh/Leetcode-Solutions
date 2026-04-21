#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0;
        int j = colors.size() - 1;  
        int res = 0;

        while (i < j)
        {
            if (colors[i] == colors[j]) 
                i++;
            else
            {
                res = max(res, j - i); 
                break;
            }
        }

        i = 0;
        j = colors.size() - 1;  

        while (i < j)
        {
            if (colors[i] == colors[j]) 
                j--;
            else
            {
                res = max(res, j - i); 
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    // Sample Test Case 1
    vector<int> colors1 = {1, 1, 1, 6, 1, 1, 1};
    cout << "Output 1: " << obj.maxDistance(colors1) << endl;

    // Sample Test Case 2
    vector<int> colors2 = {1, 8, 3, 8, 3};
    cout << "Output 2: " << obj.maxDistance(colors2) << endl;

    // Sample Test Case 3
    vector<int> colors3 = {0, 1};
    cout << "Output 3: " << obj.maxDistance(colors3) << endl;

    return 0;
}