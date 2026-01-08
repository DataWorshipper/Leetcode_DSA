class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MIN;

        for (int u = 0; u < n; u++) {
            long long sum = vals[u];
            priority_queue<int, vector<int>, greater<int>> pq;

            for (int v : adj[u]) {
                if (vals[v] <= 0) continue;

                pq.push(vals[v]);
                sum += vals[v];

                if ((int)pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }

            ans = max(ans, (int)sum);
        }

        return ans;
    }
};
