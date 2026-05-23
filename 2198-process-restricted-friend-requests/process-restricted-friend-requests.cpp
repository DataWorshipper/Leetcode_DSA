class Solution {
public:

    class DSU {
    public:

        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int u) {
            if (parent[u] == u)
                return u;

            return parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {

            int pu = find(u);
            int pv = find(v);

            if (pu == pv)
                return;

            if (rank[pu] < rank[pv])
                swap(pu, pv);

            parent[pv] = pu;

            if (rank[pu] == rank[pv])
                rank[pu]++;
        }
    };

    vector<bool> friendRequests(
        int n,
        vector<vector<int>>& restrictions,
        vector<vector<int>>& requests) {

        DSU main_dsu(n);

        vector<bool> ans;

        for (auto &r : requests) {

            int u = r[0];
            int v = r[1];

            DSU copy_dsu = main_dsu;

            copy_dsu.unite(u, v);

            bool ok = true;

            for (auto &x : restrictions) {

                int a = x[0];
                int b = x[1];

                if (copy_dsu.find(a) ==
                    copy_dsu.find(b)) {

                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);

            if (ok)
                main_dsu = copy_dsu;
        }

        return ans;
    }
};