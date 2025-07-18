class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int fp(int u) {
        if (u == parent[u]) return u;
        return parent[u] = fp(parent[u]);
    }

    void usize(int u, int v) {
        int pu = fp(u);
        int pv = fp(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        int nx[] = {-1, 0, 0, 1};
        int ny[] = {0, -1, 1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + nx[k];
                        int nj = j + ny[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            if (dsu.fp(ni * n + nj) != dsu.fp(n * i + j)) {
                                dsu.usize(ni * n + nj, n * i + j);
                            }
                        }
                    }
                }
            }
        }

      
        int m = *max_element(dsu.size.begin(), dsu.size.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + nx[k];
                        int nj = j + ny[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            s.insert(dsu.fp(ni * n + nj));
                        }
                    }
                    int sum = 0;
                    for (auto it : s) {
                        sum += dsu.size[it];
                    }
                    m = max(m, sum + 1);
                    s.clear();
                }
            }
        }

        return m;
    }
};
