class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
        }

        target--;

        vector<int> vis(n, 0);
        vis[0] = 1;

        queue<tuple<int, int, double>> q;
        q.push({0, 0, 1.0});

        while (!q.empty()) {
            int node = get<0>(q.front());
            int time = get<1>(q.front());
            double p = get<2>(q.front());
            q.pop();

            if (node == target) {
                if (t == time) return p;
                else if (time > t) return 0;

                int friends = 0;
                for (auto& it : adj[node]) {
                    if (!vis[it]) friends++;
                }
                if (friends == 0) return p;
                else return 0;
            }

                int f=0;
                for (auto& it : adj[node]) {
                    if(!vis[it])
                    f++;
                }
            for (auto& it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    double new_p=p*(1.0/f);
                    q.push({it, time + 1, new_p});
                }
            }
        }

        return 0;
    }
};
