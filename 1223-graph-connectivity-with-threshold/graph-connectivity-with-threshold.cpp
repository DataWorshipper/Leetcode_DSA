#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findparent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findparent(parent[u]);
    }

    void unite(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n);

        for (int i =threshold+1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                
                dsu.unite(i, j);
            }
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (dsu.findparent(u) == dsu.findparent(v))
                ans[i] = true;
        }

        return ans;
    }
};
