class Solution {
    pair<bool, int> bfs(vector<vector<pair<int, int>>>& adj,
                        vector<int>& visited, int node) {
        int n = adj.size();

        queue<int> q;
        q.push(node);
        visited[node] = 1;

        bool is = false;
        int mini = 1e6;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto [neb, dis] : adj[cur]) {
                mini = min(mini, dis);
                if (!visited[neb]) {

                    visited[neb] = 1;
                    q.push(neb);

                    if (neb == (n - 1))
                        is = true;
                }
            }
        }

        return {is, mini};
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> visited(n, 0);

        for (auto& road : roads) {
            int n1 = road[0];
            int n2 = road[1];
            int dis = road[2];

            adj[n1 - 1].push_back({n2 - 1, dis});
            adj[n2 - 1].push_back({n1 - 1, dis});
        }
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                auto [is, mini] = bfs(adj, visited, i);

                if (is) {
                    return mini;
                }
            }
        }

        return -1;
    }
};