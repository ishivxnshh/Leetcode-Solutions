#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[], int delCol[])
    {
        vis[r][c] = 1;     
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < 4; i++)
        {
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && board[newRow][newCol] == 'O')
            {
                dfs(newRow, newCol, board, vis, delRow, delCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis, delRow, delCol);

            if (board[n - 1][j] == 'O' && !vis[n - 1][j])
                dfs(n - 1, j, board, vis, delRow, delCol);
        }

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis, delRow, delCol);

            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(i, m - 1, board, vis, delRow, delCol);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

// =======================
// 🔽 Driver Code
// =======================
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    sol.solve(board);

    cout << "Updated board:\n";
    for (const auto& row : board) {
        for (char cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}