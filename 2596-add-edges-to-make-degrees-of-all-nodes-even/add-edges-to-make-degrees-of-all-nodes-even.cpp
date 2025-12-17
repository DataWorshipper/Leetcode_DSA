class Solution {
public:
    bool hasFreeCommonNode(int a, int b, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> bad(n, false);

        bad[a] = bad[b] = true;
        for (int x : adj[a]) bad[x] = true;
        for (int x : adj[b]) bad[x] = true;

        for (int i = 0; i < n; i++) {
            if (!bad[i]) return true;
        }
        return false;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (deg[i] & 1) odd.push_back(i);
        }

        int k = odd.size();
        if (k > 4 || k == 1 || k == 3) return false;
        if (k == 0) return true;

        auto hasEdge = [&](int u, int v) {
            for (int x : adj[u]) if (x == v) return true;
            return false;
        };

     
        if (k == 2) {
            int a = odd[0], b = odd[1];
            if (!hasEdge(a, b)) return true;
            return hasFreeCommonNode(a, b, adj);
        }

       
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int a = odd[i], b = odd[j];
                if (hasEdge(a, b)) continue;

                vector<int> rem;
                for (int x : odd) {
                    if (x != a && x != b) rem.push_back(x);
                }

                int c = rem[0], d = rem[1];
                if (!hasEdge(c, d)) return true;
              
            }
        }

        return false;
    }
};
