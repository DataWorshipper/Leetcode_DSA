class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    bool unite(int u, int v) {
        u = find_parent(u);
        v = find_parent(v);

        if(u == v) return false;

        if(sz[u] < sz[v]) swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }
};

class Solution {
public:

    int normalMST(int n, vector<vector<int>>& edges) {

        DSU dsu(n);

        int cost = 0;
        int edgesUsed = 0;

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dsu.unite(u, v)) {
                cost += w;
                edgesUsed++;
            }
        }

        if(edgesUsed != n - 1) return 1e9;

        return cost;
    }

    int banEdgeMST(int n, vector<vector<int>>& edges, int banEdge) {

        DSU dsu(n);

        int cost = 0;
        int edgesUsed = 0;

        for(int i = 0; i < edges.size(); i++) {

            if(i == banEdge) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if(dsu.unite(u, v)) {
                cost += w;
                edgesUsed++;
            }
        }

        if(edgesUsed != n - 1) return 1e9;

        return cost;
    }

    int forceEdgeMST(int n, vector<vector<int>>& edges, int forceEdge) {

        DSU dsu(n);

        int cost = 0;
        int edgesUsed = 0;

        int u = edges[forceEdge][0];
        int v = edges[forceEdge][1];
        int w = edges[forceEdge][2];

        dsu.unite(u, v);

        cost += w;
        edgesUsed++;

        for(int i = 0; i < edges.size(); i++) {

            if(i == forceEdge) continue;

            int nu = edges[i][0];
            int nv = edges[i][1];
            int nw = edges[i][2];

            if(dsu.unite(nu, nv)) {
                cost += nw;
                edgesUsed++;
            }
        }

        if(edgesUsed != n - 1) return 1e9;

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges
    ) {

        int m = edges.size();

        for(int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
        [&](auto &a, auto &b) {
            return a[2] < b[2];
        });

        int baseMST = normalMST(n, edges);

        vector<int> critical;
        vector<int> pseudo;

        for(int i = 0; i < m; i++) {

            int withoutEdge = banEdgeMST(n, edges, i);

            if(withoutEdge > baseMST) {
                critical.push_back(edges[i][3]);
                continue;
            }

            int withEdge = forceEdgeMST(n, edges, i);

            if(withEdge == baseMST) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};