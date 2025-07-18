class DSU {
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

    void unionrank(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);
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

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
      sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
});
int comp=n;
DSU dsu(n);
int m=INT_MIN;
int c=0;
for(auto it:edges)
{
    int u=it[0];
    int v=it[1];
    int w=it[2];


if(dsu.findparent(u)!=dsu.findparent(v))
{
    dsu.unionrank(u,v);
    comp--;
    m=max(m,w);
    if(comp==k)
    {
        c=m;
        break;
    }
}

}

return c;
    }
};