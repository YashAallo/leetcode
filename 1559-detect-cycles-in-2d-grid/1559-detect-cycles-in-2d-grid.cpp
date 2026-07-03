class Solution {
    int dir[5] = {1, 0, -1, 0, 1};

    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,
             pair<int, int> par, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;

        bool ans = false;
        for (int k = 0; k < 4; k++) {
            int r = i + dir[k];
            int c = j + dir[k + 1];

            if (r >= 0 && r < n && c >= 0 && c < m &&
                grid[r][c] == grid[i][j]) {

                pair<int, int> p = {r, c};

                if (!visited[r][c]) {
                    ans = ans || dfs(grid, visited, {i, j}, r, c);
                } else if (par != p) {
                    return true;
                }
            }
        }

        return ans;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, {-1, -1}, i, j))
                        return true;
                }
            }
        }

        return false;
    }
};