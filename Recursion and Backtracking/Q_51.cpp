#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int duprow = row;
        int dupcol = col;

        // upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        // left row
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        col = dupcol;

        // lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    } 

    void solve(int col, vector<string> &board,
               vector<vector<string>> &res, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, board, res, n);
        return res;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);

    cout << "Total solutions: " << ans.size() << "\n\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (auto &row : ans[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
