#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string decodeCiphertext(string encodedText, int rows) 
    {
        if (rows == 0) return "";

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        // for (int startCol = 0; startCol < cols; startCol++)
        // {
        //     int i = 0;
        //     int j = startCol;

        //     while (i < rows && j < cols)
        //     {
        //         result += encodedText[i * cols + j];
        //         i++;
        //         j++;
        //     }
        // }

        for (int startCol = 0; startCol < cols; startCol++)
        {
            for (int j = startCol; j < n; j += (cols + 1))
            {
                result += encodedText[j];
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ')
        {
            result.pop_back();
        }
        
        return result;
    }
};

int main()
{
    Solution obj;

    vector<pair<string, int>> testCases =
    {
        {"ch   ie   pr", 3},   // Expected: "cipher"
        {"iveo    eed   l te   olc", 4}, // Expected: "i love leetcode"
        {"coding", 1},        // Expected: "coding"
        {" b  ac", 2},        // Expected: " abc"
        {"", 5},              // Expected: ""
        {"a", 1},             // Expected: "a"
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        string encodedText = testCases[i].first;
        int rows = testCases[i].second;

        string result = obj.decodeCiphertext(encodedText, rows);

        cout << "Test Case " << i + 1 << ":\n";
        cout << "Encoded: \"" << encodedText << "\"\n";
        cout << "Rows: " << rows << "\n";
        cout << "Decoded: \"" << result << "\"\n";
        cout << "--------------------------\n";
    }

    return 0;
}