class Solution {
public:
    bool dfsPath(int u, int target, vector<vector<int>> &adj, vector<int> &path,vector<int>&vis) {
        path.push_back(u);
        vis[u]=1;
        if (u == target) return true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfsPath(v, target, adj, path,vis)) return true;
            }
        }
        path.pop_back();
        return false;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        queue<pair<int,int>> q;
        vector<int> vis1(n, 0), d1(n);
        q.push({0, 0});
        vis1[0] = 1;
        while (!q.empty()) {
            auto [u, dist] = q.front(); q.pop();
            d1[u] = dist;
            for (int nei : adj[u]) {
                if (!vis1[nei]) {
                    vis1[nei] = 1;
                    q.push({nei, dist + 1});
                }
            }
        }
        int node = max_element(d1.begin(), d1.end()) - d1.begin();

        // Second BFS
        queue<pair<int,int>> q2;
        vector<int> vis2(n, 0), d2(n);
        q2.push({node, 0});
        vis2[node] = 1;
        while (!q2.empty()) {
            auto [u, dist] = q2.front(); q2.pop();
            d2[u] = dist;
            for (int nei : adj[u]) {
                if (!vis2[nei]) {
                    vis2[nei] = 1;
                    q2.push({nei, dist + 1});
                }
            }
        }
        int node1 = max_element(d2.begin(), d2.end()) - d2.begin();

     
        vector<int> path;
        vector<int>vis(n,0);
        dfsPath(node, node1,adj, path,vis);

        int m = path.size();
        if (m % 2 == 1) return {path[m / 2]};
        else return {path[m / 2 - 1], path[m / 2]};
    }
};
