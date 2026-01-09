class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp1(m, vector<long long>(n));
        vector<vector<long long>> dp2(m, vector<long long>(n));

        dp1[0][0] = grid[0][0];
        dp2[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp1[i][0] = max(dp1[i-1][0] * grid[i][0], dp2[i-1][0] * grid[i][0]);
            dp2[i][0] = min(dp1[i-1][0] * grid[i][0], dp2[i-1][0] * grid[i][0]);
        }

        for (int j = 1; j < n; j++) {
            dp1[0][j] = max(dp1[0][j-1] * grid[0][j], dp2[0][j-1] * grid[0][j]);
            dp2[0][j] = min(dp1[0][j-1] * grid[0][j], dp2[0][j-1] * grid[0][j]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long a = dp1[i-1][j] * grid[i][j];
                long long b = dp1[i][j-1] * grid[i][j];
                long long c = dp2[i-1][j] * grid[i][j];
                long long d = dp2[i][j-1] * grid[i][j];

                dp1[i][j] = max({a, b, c, d});
                dp2[i][j] = min({a, b, c, d});
            }
        }

        if (dp1[m-1][n-1] < 0) return -1;
        return (int)(dp1[m-1][n-1] % 1000000007);
    }
};
