class Solution {
    int sum = 0;
    vector<int> res;

    void dfs(int node,
             vector<vector<pair<int,int>>>& adj,
             vector<int>& vis)
    {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                sum += it.second;
                dfs(it.first, adj, vis);
            }
        }
    }

    void result(int node,
                int parent,
                vector<vector<pair<int,int>>>& adj)
    {
        for (auto it : adj[node]) {
            if (it.first == parent) continue;

            int direction = it.second;

            if (direction == 1) {
                res[it.first] = res[node] - 1;
            } else {
                res[it.first] = res[node] + 1;
            }

            result(it.first, node, adj);
        }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);
        res.assign(n, 0);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> vis(n, 0);

        dfs(0, adj, vis);
        res[0] = sum;
        result(0, -1, adj);

        return res;
    }
};
