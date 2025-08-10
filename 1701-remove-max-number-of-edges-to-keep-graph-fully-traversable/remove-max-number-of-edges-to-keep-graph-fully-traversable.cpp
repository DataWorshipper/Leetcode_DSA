class DSU {
public:
    vector<int> rank, parent;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findparent(parent[u]); 
    }

    void unionbyrank(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

bool isConnected(DSU &dsu, int n) {
    int root = dsu.findparent(0);
    for (int i = 1; i < n; i++) {
        if (dsu.findparent(i) != root) return false;
    }
    return true;
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu1(n), dsu2(n);
        int c1 = 0, c2 = 0, c3 = 0;
        int m = edges.size();

        for (auto it : edges) {
            int type = it[0];
            int u = it[1] - 1;
            int v = it[2] - 1;

            if (type == 3) {
                if (dsu1.findparent(u) != dsu1.findparent(v) &&
                    dsu2.findparent(u) != dsu2.findparent(v)) {
                    dsu1.unionbyrank(u, v);
                    dsu2.unionbyrank(u, v);
                    c3++;
                }

               
            }
        }

        for (auto it : edges) {
            int type = it[0];
            int u = it[1] - 1;
            int v = it[2] - 1;

            if (type == 1) {
                if (dsu1.findparent(u) != dsu1.findparent(v)) {
                    dsu1.unionbyrank(u, v);
                    c1++;
                }
               
            }
        }

        for (auto it : edges) {
            int type = it[0];
            int u = it[1] - 1;
            int v = it[2] - 1;

            if (type == 2) {
                if (dsu2.findparent(u) != dsu2.findparent(v)) {
                    dsu2.unionbyrank(u, v);
                    c2++;
                }
               
            }
        }

        if (!isConnected(dsu1, n) || !isConnected(dsu2, n))
            return -1;
        else
            return m - (c3 + c1 + c2);
    }
};
