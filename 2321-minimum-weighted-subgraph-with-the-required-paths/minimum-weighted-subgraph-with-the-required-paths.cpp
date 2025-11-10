typedef long long ll;
const ll INF = 4e18;

class Solution {
public:
    vector<ll> dijkstra(int n, int start, vector<vector<pair<int,int>>> &g) {
        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;
            for(auto &e : g[u]) {
                int v = e.first, w = e.second;
                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> g(n), rg(n);
        for(auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            rg[e[1]].push_back({e[0], e[2]});
        }

        auto dist1 = dijkstra(n, src1, g);
        auto dist2 = dijkstra(n, src2, g);
        auto distD = dijkstra(n, dest, rg);

        ll ans = INF;
        for(int x = 0; x < n; x++) {
            if(dist1[x] == INF || dist2[x] == INF || distD[x] == INF) continue;
            ans = min(ans, dist1[x] + dist2[x] + distD[x]);
        }

        return ans == INF ? -1 : ans;
    }
};
