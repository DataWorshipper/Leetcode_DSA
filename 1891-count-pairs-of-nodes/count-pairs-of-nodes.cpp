class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

        // degree[i] = total incident edges on node i (with multiplicity)
        vector<int> degree(n + 1, 0);

        // cnt[a][b] = number of edges between a and b (a < b)
        vector<unordered_map<int,int>> cnt(n + 1);

        // build degree + cnt
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            degree[u]++;
            degree[v]++;
            int a = min(u, v);
            int b = max(u, v);
            cnt[a][b]++;
        }

        // sorted degree values (identity not needed for base count)
        vector<int> deg;
        for (int i = 1; i <= n; i++) {
            deg.push_back(degree[i]);
        }
        sort(deg.begin(), deg.end());

        vector<int> ans;

        // process each query
        for (int q : queries) {

            long long tot = 0;

            // ---- base count: ordered pairs (i, j) ----
            for (int i = 0; i < n; i++) {
                int need = q - deg[i];
                auto it = upper_bound(deg.begin(), deg.end(), need);
                tot += (deg.end() - it);
            }

            // ---- remove self-pairs (i, i) ----
            for (int i = 0; i < n; i++) {
                if (2 * deg[i] > q) {
                    tot--;
                }
            }

            // ---- unordered pairs ----
            long long cur = tot / 2;

            // ---- correction using cnt[a][b] ----
            for (int a = 1; a <= n; a++) {
                for (auto &it : cnt[a]) {
                    int b = it.first;
                    int c = it.second;
                    int s = degree[a] + degree[b];
                    if (s > q && s - c <= q) {
                        cur--;
                    }
                }
            }

            ans.push_back((int)cur);
        }

        return ans;
    }
};
