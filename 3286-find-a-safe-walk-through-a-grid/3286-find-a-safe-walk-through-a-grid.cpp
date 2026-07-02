class Solution {
    int dir[5] = {1, 0, -1, 0, 1};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = grid[0][0];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [val, i, j] = pq.top();
            pq.pop();

            if (val > dist[i][j])
                continue;

            if (i == n - 1 && j == m - 1) {
                break;
            }

            for (int k = 0; k < 4; k++) {
                int r = i + dir[k];
                int c = j + dir[k + 1];

                if (r >= 0 && r < n && c >= 0 && c < m) {

                    if (dist[r][c] > grid[r][c] + val) {
                        dist[r][c] = val + grid[r][c];

                        pq.push({dist[r][c], r, c});
                    }
                }
            }
        }

        int ans = dist[n - 1][m - 1];
        cout << ans;

        return ans < health;
    }
};