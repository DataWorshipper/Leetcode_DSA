class Solution {
    static const int LOG = 20;
    int n;
    vector<vector<pair<int,int>>> adj;
    vector<int> depth;
    vector<long long> dist;
    vector<vector<int>> up;

    void dfs(int v, int p) {
        up[0][v] = p;
        for (auto &[u, w] : adj[v]) {
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            dist[u] = dist[v] + w;
            dfs(u, v);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];

        for (int i = 0; i < LOG; i++)
            if (diff & (1 << i))
                a = up[i][a];

        if (a == b) return a;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][a] != up[i][b]) {
                a = up[i][a];
                b = up[i][b];
            }
        }
        return up[0][a];
    }

    long long d(int u, int v) {
        int w = lca(u, v);
        return dist[u] + dist[v] - 2LL * dist[w];
    }

public:
    vector<int> minimumWeight(vector<vector<int>>& edges,
                              vector<vector<int>>& queries) {

        n = edges.size() + 1;
        adj.assign(n, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        depth.assign(n, 0);
        dist.assign(n, 0);
        up.assign(LOG, vector<int>(n, -1));

        dfs(0, -1);

        for (int i = 1; i < LOG; i++) {
            for (int v = 0; v < n; v++) {
                if (up[i - 1][v] != -1)
                    up[i][v] = up[i - 1][ up[i - 1][v] ];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int a = q[0], b = q[1], c = q[2];
            long long res = d(a, b) + d(a, c) + d(b, c);
            res /= 2;
            ans.push_back((int)res);
        }
        return ans;
    }
};
