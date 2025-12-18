class Solution {
    int dp[1001][2001];

    int f(int index, int coins, vector<vector<int>>& prefix) {
        if (coins == 0) return 0;
        if (index == prefix.size()) return 0;

        if (dp[index][coins] != -1)
            return dp[index][coins];

        int ans=f(index+1,coins,prefix);

        int m = prefix[index].size();
        for (int x = 1; x <= min(coins, m); x++) {
            ans = max(ans,
                      prefix[index][x-1] +
                      f(index + 1, coins - x, prefix));
        }

        return dp[index][coins] = ans;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));

        int n = piles.size();
        vector<vector<int>> prefix(n);

        for (int i = 0; i < n; i++) {
            int m = piles[i].size();
            prefix[i].resize(m);
            prefix[i][0] = piles[i][0];
            for (int j = 1; j < m; j++) {
                prefix[i][j] = prefix[i][j - 1] + piles[i][j];
            }
        }

        return f(0, k, prefix);
    }
};
