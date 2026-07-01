class Solution {

    int dis[5] = {1, 0, -1, 0, 1};

    void bfs(vector<vector<int>>& distance, vector<pair<int, int>>& thief) {

        queue<pair<int, int>> q;
        int n = distance.size();

        for (auto [i, j] : thief) {
            q.push({i, j});
            distance[i][j] = 0;
        }

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = a + dis[k];
                int c = b + dis[k + 1];

                if (r >= 0 && r < n && c >= 0 && c < n &&
                    distance[r][c] == -1) {
                    distance[r][c] = distance[a][b] + 1;
                    q.push({r, c});
                }
            }
        }
    }

    int func(vector<vector<int>>& distance) {

        int n = distance.size();

        vector<vector<int>> best(n, vector<int>(n, -1));

        priority_queue<tuple<int, int, int>> pq;
        // {currentSafeness, row, col}

        pq.push({distance[0][0], 0, 0});
        best[0][0] = distance[0][0];

        while (!pq.empty()) {

            auto [safe, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return safe;

            if (safe < best[r][c])
                continue;

            for (int k = 0; k < 4; k++) {

                int nr = r + dis[k];
                int nc = c + dis[k + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                    int newSafe = min(safe, distance[nr][nc]);

                    if (newSafe > best[nr][nc]) {
                        best[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }

        return 0;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        vector<pair<int, int>> thief;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    thief.push_back({i, j});
            }
        }

        vector<vector<int>> distance(n, vector<int>(n, -1));

        bfs(distance, thief);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                cout << distance[i][j] << " ";
            }
            cout << endl;
        }

        return func(distance);
    }
};