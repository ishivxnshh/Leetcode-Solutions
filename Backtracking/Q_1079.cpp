#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    void backtrack(unordered_map<char, int> &freq_map, int &count)
    {
        for (auto &[ch, freq] : freq_map)
        {
            if (freq > 0)
            {
                freq--;  // Use the letter
                count++; // Increment valid sequence count
                backtrack(freq_map, count);
                freq++; // Undo the choice (backtrack)
            }
        }
    }

    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int> freq_map;
        for (char ch : tiles)
        {
            freq_map[ch]++;
        }
        int count = 0;
        backtrack(freq_map, count);
        return count;
    }
};

// Driver function to test the solution
int main()
{
    Solution sol;

    // Test cases
    string testCases[] = {"AAB", "AAABBC", "XYZ"};
    int expectedResults[] = {8, 188, 15}; // Expected results for verification

    for (int i = 0; i < 3; i++)
    {
        string tiles = testCases[i];
        int result = sol.numTilePossibilities(tiles);
        cout << "Test Case " << i + 1 << " (tiles = \"" << tiles << "\"): " << result;
        if (result == expectedResults[i])
        {
            cout << " (PASS)";
        }
        else
        {
            cout << " (FAIL, Expected: " << expectedResults[i] << ")";
        }
        cout << endl;
    }

    return 0;
}