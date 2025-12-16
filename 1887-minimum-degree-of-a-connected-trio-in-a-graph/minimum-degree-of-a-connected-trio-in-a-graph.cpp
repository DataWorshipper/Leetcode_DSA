class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> degree(n, 0);

        for (auto it : edges) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            if (!adj[u][v]) {
                adj[u][v] = 1;
                adj[v][u] = 1;
                degree[u]++;
                degree[v]++;
            }
        }

        int m = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (adj[i][j] && adj[j][k] && adj[k][i]) {
                        int deg = degree[i] + degree[j] + degree[k] - 6;
                        m = min(m, deg);
                    }
                }
            }
        }

        if (m == INT_MAX) return -1;
        return m;
    }
};
