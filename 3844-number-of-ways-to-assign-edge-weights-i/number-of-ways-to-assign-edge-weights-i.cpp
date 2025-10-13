class Solution {
public: 
    const int MOD = 1e9+7;

    int binpow(int a, long long n)
    {   
        if(n == 0) 
            return 1;
        long long half = binpow(a, n / 2);
        long long res = (half * half) % MOD;
        if(n % 2 == 1) 
            res = (res * a) % MOD;
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        // Build adjacency list
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

      
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;

        int max_depth = 0;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(depth[v] == -1) { 
                    depth[v] = depth[u] + 1;
                    q.push(v);
                    max_depth = max(max_depth, depth[v]);
                }
            }
        }

     
        if(max_depth == 0) return 0; 

        return binpow(2, max_depth - 1);
    }
};
