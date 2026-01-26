class Solution {
public:
    int diam;

    int dfs(int u, int p, vector<vector<int>>& adj) {
        int mx1 = 0, mx2 = 0;

        for (int v : adj[u]) {
            if (v == p) continue;
            int d = dfs(v, u, adj) + 1;
            if (d > mx1) {
                mx2 = mx1;
                mx1 = d;
            } else if (d > mx2) {
                mx2 = d;
            }
        }

        diam = max(diam, mx1 + mx2);
        return mx1;
    }

    int getDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        diam = 0;
        dfs(0, -1, adj);
        return diam;
    }

    int minimumDiameterAfterMerge(
        vector<vector<int>>& edges1,
        vector<vector<int>>& edges2
    ) {
        int D1 = getDiameter(edges1.size() + 1, edges1);
        int D2 = getDiameter(edges2.size() + 1, edges2);

        int R1 = (D1 + 1) / 2;
        int R2 = (D2 + 1) / 2;

        return max({D1, D2, R1 + R2 + 1});
    }
};
