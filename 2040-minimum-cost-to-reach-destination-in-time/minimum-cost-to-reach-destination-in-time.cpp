class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        const int INF = 1e9;

        // dist[node][time] = minimum cost to reach node in exactly 'time'
        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INF));

        using T = tuple<int,int,int>; // cost, time, node
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0});

        while (!pq.empty()) {
            auto [cost, time, u] = pq.top();
            pq.pop();

            if (cost != dist[u][time]) continue;

            if (u == n - 1) return cost;

            for (auto &[v, wt] : adj[u]) {
                int nt = time + wt;
                if (nt > maxTime) continue;

                int nc = cost + passingFees[v];

                if (nc < dist[v][nt]) {
                    dist[v][nt] = nc;
                    pq.push({nc, nt, v});
                }
            }
        }

        return -1;
    }
};