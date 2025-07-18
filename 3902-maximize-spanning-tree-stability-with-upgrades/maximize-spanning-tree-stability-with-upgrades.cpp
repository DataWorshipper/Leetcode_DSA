class Solution {
public:
    class DSU {
    private:
        vector<int> parent, rank;

    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findparent(int u) {
            if (u == parent[u])
                return u;
            return parent[u] = findparent(parent[u]);
        }

        void unionrank(int pu, int pv) {
            if (pu == pv) return;

            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> must, notmust;
        for (auto it : edges) {
            if (it[3] == 1)
                must.push_back({it[0], it[1], it[2]});
            else
                notmust.push_back({it[2], it[0], it[1]});
        }

        DSU dsu(n);
        int ans = INT_MAX;

        for (auto it : must) {
            int u = it[0], v = it[1], s = it[2];
            int pu = dsu.findparent(u);
            int pv = dsu.findparent(v);
            if (pu == pv) return -1; 
            dsu.unionrank(pu, pv);
            ans = min(ans, s);
        }

       
        sort(notmust.begin(), notmust.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        vector<int> used_non_must; 

        for (auto it : notmust) {
            int s = it[0], u = it[1], v = it[2];
            int pu = dsu.findparent(u);
            int pv = dsu.findparent(v);
            if (pu != pv) {
                dsu.unionrank(pu, pv);
                used_non_must.push_back(s);
            }
        }

        int root = dsu.findparent(0);
        for (int i = 1; i < n; i++) {
            if (dsu.findparent(i) != root) return -1;
        }

       
        sort(used_non_must.begin(), used_non_must.end());

        for (int i = 0; i < used_non_must.size() && i < k; i++) {
            used_non_must[i] *= 2;
        }

        int min_non_must = INT_MAX;
        if (!used_non_must.empty()) {
            min_non_must = *min_element(used_non_must.begin(), used_non_must.end());
        }

        ans = min(ans, min_non_must);

        return ans;
    }
};
