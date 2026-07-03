class Solution {
    bool bfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        queue<pair<int, int>> q;
        q.push({node, -1});

        visited[node] = 0;

        bool ans = false;

        while (!q.empty()) {
            int len = q.size();

            auto [cur_node, par] = q.front();
            q.pop();

            for (auto neb : graph[cur_node]) {
                if (visited[neb] > 1 + visited[cur_node]) {

                    q.push({neb, cur_node});
                    visited[neb] = 1 + visited[cur_node];

                } 
                
                 if ( visited[neb]!=1e5 && par != neb) {

                    if ( (visited[neb]+visited[cur_node]+1) % 2 != 0) {
                        cout <<(visited[neb]+visited[cur_node]+1) ;
                        return true;
                    }
                }
            }
        }
        return ans;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int nodes = graph.size();

        vector<int> visited(nodes, 1e5);

        for (int i = 0; i < nodes; i++) {

            if (visited[i] == 1e5) {

                if (bfs(graph, visited, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};