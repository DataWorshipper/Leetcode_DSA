class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        for (auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = true;
            connected[v][u] = true;
        }

        int maxRank = 0;
      
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int rank = degree[u] + degree[v] - (connected[u][v] ? 1 : 0);
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
