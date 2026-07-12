class Solution {
public:
    bool ok(int a, int b, vector<vector<int>>& grid, int limit) {
        int m = grid.size();

        for (int r = 0; r < m; r++) {
            if (abs(grid[r][b] - grid[r][a]) > limit)
                return false;
        }

        return true;
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid[0].size();

        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ok(j, i, grid, limit)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};