class Solution {
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i,
             int j) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push({i, j});

        while (!q.empty()) {

            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = a + row[k];
                int c = b + col[k];

                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] &&
                    grid[r][c] == '1') {
                    q.push({r, c});
                    visited[r][c] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {

                    bfs(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};