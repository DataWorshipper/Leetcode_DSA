class Solution {
public:
    bool isBipartite(vector<vector<int>>& points, int d) {
        int n = points.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue;

           
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < n; v++) {
                    if (u == v) continue;

                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                  
                    if (dist < d) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } 
                        else if (color[v] == color[u]) {
                            return false; 
                        }
                    }
                }
            }
        }
        return true;
    }

    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return 0;

        int max_d = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                max_d = max(max_d, dist);
            }
        }

        int low = 0, high = max_d, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isBipartite(points, mid)) {
                ans = mid;        // feasible
                low = mid + 1;    // try bigger
            } else {
                high = mid - 1;   // too big
            }
        }
        return ans;
    }
};
