#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> splitString(string &s, char delimiter)
    {
        vector<int> ans;
        int start = 0;
        int end = s.find(delimiter, start);
        while (end != string::npos)
        {
            int temp = stoi(s.substr(start, end - start));
            ans.push_back(temp);
            start = end + 1;
            end = s.find(delimiter, start);
        }
        int temp = stoi(s.substr(start, end - start));
        ans.push_back(temp);
        return ans;
    }

    int compareVersion(string version1, string version2)
    {
        // Brute - Force Approach(tc : m + n, sc : m + n)

        //             vector<int>
        //                 v1 = splitString(version1, '.');
        // vector<int> v2 = splitString(version2, '.');

        // OR

        //     vector<int>
        //         v1, v2;
        // istringstream iss1(version1), iss2(version2);
        // string token;
        // while (getline(iss1, token, '.'))
        // {
        //     v1.push_back(stoi(token));
        // }
        // while (getline(iss2, token, '.'))
        // {
        //     v2.push_back(stoi(token));
        // }

        // for (int i = 0; i < max(v1.size(), v2.size()); i++)
        // {
        //     int val1 = (i < v1.size() ? v1[i] : 0);
        //     int val2 = (i < v2.size() ? v2[i] : 0);
        //     if (val1 < val2)
        //     {
        //         return -1;
        //     }
        //     else if (val1 > val2)
        //     {
        //         return 1;
        //     }
        // }
        // return 0;

        // Optimized Approach(tc : max(m, n), sc : 1) 
        int i = 0;
        int j = 0;
        while (i < version1.size() || j < version2.size())
        {
            int val1 = 0, val2 = 0;
            while (i < version1.size() && version1[i] != '.')
            {
                val1 = val1 * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            while (j < version2.size() && version2[j] != '.')
            {
                val2 = val2 * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            if (val1 < val2)
                return -1;
            else if (val1 > val2)
                return 1;
        }
        return 0;
    }
};

// Driver Code
int main()
{
    Solution solution;
    vector<pair<string, string>> testCases = {
        {"1.01", "1.001"},
        {"1.0", "1.0.0"},
        {"0.1", "1.1"},
        {"1.2", "1.10"},
        {"2.1", "2.1"},
        {"1.2.3", "1.2.3.4"},
        {"1.10.1", "1.10"}};

    for (auto &test : testCases)
    {
        cout << "Comparing: " << test.first << " vs " << test.second << " -> ";
        int result = solution.compareVersion(test.first, test.second);
        if (result == 0)
        {
            cout << "Equal";
        }
        else if (result == -1)
        {
            cout << test.first << " is smaller";
        }
        else
        {
            cout << test.first << " is greater";
        }
        cout << endl;
    }

    return 0;
}
