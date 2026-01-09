class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MIN));
        vector<vector<long long>> best(m, vector<long long>(n, LLONG_MIN));

        best[0][0] = -grid[0][0];

        for (int j = 1; j < n; j++) {
            dp[0][j] = best[0][j-1] + grid[0][j];
            best[0][j] = max({best[0][j-1], -(long long)grid[0][j]});
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = best[i-1][0] + grid[i][0];
            best[i][0] = max({best[i-1][0], -(long long)grid[i][0]});
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(best[i-1][j], best[i][j-1]) + grid[i][j];
                best[i][j] = max({
                    best[i-1][j],
                    best[i][j-1],
                    dp[i][j]-(long long)grid[i][j],
                    -(long long)grid[i][j]
                });
            }
        }

        long long ans = LLONG_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return (int)ans;
    }
};
