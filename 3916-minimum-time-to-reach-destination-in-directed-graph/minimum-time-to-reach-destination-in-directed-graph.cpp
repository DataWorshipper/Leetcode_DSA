
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int start = e[2], end = e[3];
            adj[u].push_back({v, start, end});
        }

        const int INF = INT_MAX;
        vector<int> dist(n, INF);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0}); // time, node

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (time != dist[u]) continue;

            if (u == n - 1) return time;

            for (auto [v, start, end] : adj[u]) {
                int depart = max(time, start);

                if (depart > end) continue;

                int arrival = depart + 1;

                if (arrival < dist[v]) {
                    dist[v] = arrival;
                    pq.push({arrival, v});
                }
            }
        }

        return -1;
    }
};
