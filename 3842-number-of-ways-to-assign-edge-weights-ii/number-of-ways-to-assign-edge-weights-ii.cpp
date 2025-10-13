class Solution {
public:
    const int MOD = 1e9 + 7;
    static const int MAXN = 100005;
    static const int LOG = 20;

    int dp[MAXN][LOG];
    vector<int> depth;

    int binexp(int a, int m) {
        if (m == 0) return 1;
        long long half = binexp(a, m / 2);
        long long res = (half * half) % MOD;
        if (m % 2) res = (res * a) % MOD;
        return res;
    }

    void lifting(int u, int parent) {
        if(parent==-1)
        {
            dp[u][0]=u;
        }
        else
        dp[u][0] = parent;

        for(int i = 1; i < LOG; i++)
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }

    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        lifting(node, parent);

        for(int nxt : adj[node]) {
            if(!vis[nxt]) {
                depth[nxt] = depth[node] + 1;
                 
                dfs(nxt, node, vis, adj);
            }
        }
    }

    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int i = LOG - 1; i >= 0; i--)
            if((diff >> i) & 1)
                u = dp[u][i];

        if(u == v) return u;

        for(int i = LOG - 1; i >= 0; i--)
            if(dp[u][i] != dp[v][i])
                u = dp[u][i], v = dp[v][i];

        return dp[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        depth.assign(n + 1, 0);
        vector<int> vis(n + 1, 0);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        memset(dp, 0, sizeof(dp));
        depth[1] = 0;
        dfs(1, -1, vis, adj); 

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            int L = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[L];
            if(dist==0)
            ans[i]=0;
            else
            ans[i] = binexp(2, dist - 1);
        }

        return ans;
    }
};
