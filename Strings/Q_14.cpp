#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0)
        {
            return "";
        }
        
        for (int i = 0; i < strs[0].length(); i++) 
        {
            char ch = strs[0][i];
            
            for (int j = 1; j < strs.size(); j++) 
            {
                if (i >= strs[j].length() || ch != strs[j][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};

// **Driver Code**
int main() 
{
    Solution sol;
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"apple", "apricot", "apartment"};
    vector<string> strs4 = {"", "b"};
    vector<string> strs5 = {"same", "same", "same"};

    cout << "Test Case 1: " << sol.longestCommonPrefix(strs1) << endl;  // Output: "fl"
    cout << "Test Case 2: " << sol.longestCommonPrefix(strs2) << endl;  // Output: ""
    cout << "Test Case 3: " << sol.longestCommonPrefix(strs3) << endl;  // Output: "ap"
    cout << "Test Case 4: " << sol.longestCommonPrefix(strs4) << endl;  // Output: ""
    cout << "Test Case 5: " << sol.longestCommonPrefix(strs5) << endl;  // Output: "same"

    return 0;
}