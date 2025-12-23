class Solution {
    vector<vector<int>> cnt;

public:
    void dfs(int node, int parent, vector<vector<int>>& adj, string &labels) {
        cnt[node][labels[node] - 'a']++;

        for (int it : adj[node]) {
            if (it == parent) continue;

            dfs(it, node, adj, labels);

            for (int i = 0; i < 26; i++) {
                cnt[node][i] += cnt[it][i];
            }
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        cnt.assign(n, vector<int>(26, 0));

        dfs(0, -1, adj, labels);

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = cnt[i][labels[i] - 'a'];
        }

        return ans;
    }
};
