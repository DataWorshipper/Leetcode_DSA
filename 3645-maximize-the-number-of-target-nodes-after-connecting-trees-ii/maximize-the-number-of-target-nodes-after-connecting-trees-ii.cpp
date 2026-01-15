class Solution {
public:
    vector<vector<int>> g1, g2;
    vector<int> even1, odd2;
    int n, m;

    void dfs1(int u, int p, int depth) {
        if (depth % 2 == 0) even1[0]++;
        for (int v : g1[u]) {
            if (v == p) continue;
            dfs1(v, u, depth + 1);
        }
    }

    void reroot1(int u, int p) {
        for (int v : g1[u]) {
            if (v == p) continue;
            even1[v] = n - even1[u];
            reroot1(v, u);
        }
    }

    void dfs2(int u, int p, int depth) {
        if (depth % 2 == 1) odd2[0]++;
        for (int v : g2[u]) {
            if (v == p) continue;
            dfs2(v, u, depth + 1);
        }
    }

    void reroot2(int u, int p) {
        for (int v : g2[u]) {
            if (v == p) continue;
            odd2[v] = m - odd2[u];
            reroot2(v, u);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n = edges1.size() + 1;
        m = edges2.size() + 1;

        g1.assign(n, {});
        g2.assign(m, {});
        for (auto &e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        even1.assign(n, 0);
        odd2.assign(m, 0);

        dfs1(0, -1, 0);
        reroot1(0, -1);

     
        dfs2(0, -1, 0);
        reroot2(0, -1);

        int bestOdd = 0;
        for (int i = 0; i < m; i++) {
            bestOdd = max(bestOdd, odd2[i]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = even1[i] + bestOdd;
        }
        return ans;
    }
};
