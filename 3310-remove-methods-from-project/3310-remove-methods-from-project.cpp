class Solution {
    void dfs(vector<vector<int>>& adj, vector<int>& mem, int k) {
        if (mem[k])
            return;

        mem[k] = 1;

        for (auto neb : adj[k]) {
            dfs(adj, mem, neb);
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {

        // adj list and indegree
        vector<vector<int>> adj(n);
        // vector<int> indegree(n);

        for (int i = 0; i < inv.size(); i++) {
            adj[inv[i][0]].push_back(inv[i][1]);
            // indegree[inv[1]]++;
        }

        vector<int> mem(n, 0);

        dfs(adj, mem, k);

        // find all indegree with 0 and push then in queue which are not in mem
        //   queue<int> q;
        //   for(int i=0;i<n;i++)
        //   {
        //      if(indegree[i]==0 && mem[i]!=0)
        //      {
        //          q.push(i);
        //      }
        //   }

        bool connection = false;
        for (auto v : inv) {
            int a = v[0];
            int b = v[1];

            if (!mem[a] && mem[b]) {
                connection = true;
                break;
            }
        }

        vector<int> all; // all  [0,1,2,3,.....,n-1]
        vector<int> ans; // all-ones in mem

        for (int i = 0; i < n; i++) {
            all.push_back(i);

            if (!mem[i]) {
                ans.push_back(i);
            }
        }

        if (connection) {

            return all;
        }

        return ans;
    }
};