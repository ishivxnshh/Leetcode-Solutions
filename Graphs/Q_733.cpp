// Time Complexity: O(N * M) for both DFS and BFS
// Space Complexity: O(N * M) for both (due to recursion stack or queue and 'ans' matrix)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // -------- DFS Helper Function --------
    void dfs(int row, int col, vector<vector<int>>& ans, int originalColor, int color, vector<int>& drow, vector<int>& dcol) {
        ans[row][col] = color;
        int n = ans.size();
        int m = ans[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == originalColor) {
                dfs(nrow, ncol, ans, originalColor, color, drow, dcol);
            }
        }
    }

    // -------- BFS Helper Function --------
    void bfs(int sr, int sc, vector<vector<int>>& ans, int originalColor, int color, vector<int>& drow, vector<int>& dcol) {
        int n = ans.size();
        int m = ans[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        ans[sr][sc] = color;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == originalColor) {
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    // -------- Main Function --------
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;
        int originalColor = image[sr][sc];

        if (originalColor == color)
            return image;

        vector<int> drow = {-1, 0, +1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        // ---- DFS call ----
        dfs(sr, sc, ans, originalColor, color, drow, dcol);

        // ---- BFS call ----
        // bfs(sr, sc, ans, originalColor, color, drow, dcol);

        return ans;
    }
};

// -------- Driver Code --------
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";
    for (auto row : result) {
        for (auto pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}