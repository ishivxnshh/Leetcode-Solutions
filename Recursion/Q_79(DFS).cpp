#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // DFS helper function to explore all 4 directions
    bool dfs(vector<vector<char>>& board, int r, int c, string word, int ind)
    {
        // Base case: all characters matched
        if (ind == word.length())
        {
            return true;
        }

        // Boundary and character check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
        {
            return false;
        }

        // Already visited or mismatch
        if (board[r][c] == ' ' || board[r][c] != word[ind])
        {
            return false;
        }

        // Mark current cell as visited
        char ch = board[r][c];
        board[r][c] = ' ';

        // Explore all 4 directions
        if (dfs(board, r + 1, c, word, ind + 1) ||
            dfs(board, r - 1, c, word, ind + 1) ||
            dfs(board, r, c + 1, word, ind + 1) ||
            dfs(board, r, c - 1, word, ind + 1))
        {
            return true;
        }

        // Backtrack: unmark visited cell
        board[r][c] = ch;

        return false;
    }

    // Main function to start DFS from every matching starting point
    bool exist(vector<vector<char>>& board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // Start DFS if first character matches
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

/*
Time Complexity: O(M * N * 3^L)
- M*N for each cell, 4^L for exploring up to L-length word in 3 directions.

Space Complexity: O(L)
- Maximum depth of recursion stack is L (length of the word).
*/

int main()
{
    vector<vector<char>> board =
    {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    Solution sol;
    bool result = sol.exist(board, word);

    if (result)
    {
        cout << "Word exists in the board." << endl;
    }
    else
    {
        cout << "Word does not exist in the board." << endl;
    }

    return 0;
}