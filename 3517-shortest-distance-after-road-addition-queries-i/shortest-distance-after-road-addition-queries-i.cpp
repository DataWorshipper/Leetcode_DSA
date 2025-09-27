class Solution {
public:
    // Dijkstra function to find shortest path from 0 to n-1
    int dijkstra(int n, vector<vector<pair<int,int>>>& adj) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0}); // {distance, node}

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int u = it.second;

            if(d > dist[u]) continue;

            for(auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
      
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < n-1; i++) {
            adj[i].push_back({i+1, 1});
        }

        vector<int> answer;

       
        for(auto &q : queries) {
            int u = q[0];
            int v = q[1];
            adj[u].push_back({v, 1}); 
            int shortest = dijkstra(n, adj); 
            answer.push_back(shortest);
        }

        return answer;
    }
};
