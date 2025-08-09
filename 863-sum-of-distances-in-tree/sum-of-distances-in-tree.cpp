class Solution {
public:
    int N;
    vector<int> count;
    vector<int> res;
    int s;

    void dfs1(vector<vector<int>>& adj, int node, int parent) {
        count[node] = 1;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            dfs1(adj, it, node);
            count[node] += count[it];
        }
    }

    void dfs(int node, int parent, vector<vector<int>>& adj, int curr_depth) {
        s += curr_depth;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            dfs(it, node, adj, curr_depth + 1);
        }
    }

    void dfs3(int node, int parent, vector<vector<int>>& adj) {
        for (auto it : adj[node]) {
            if (it == parent) continue;
            res[it] = res[node] + N - 2 * count[it];
            dfs3(it, node, adj);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.resize(n, 0);
        res.resize(n, 0);
        s = 0;

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(adj, 0, -1);       
        dfs(0, -1, adj, 0);      
        res[0] = s;             

        dfs3(0, -1, adj);        

        return res;
    }
};
