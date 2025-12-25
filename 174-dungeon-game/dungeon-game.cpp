class Solution {
    int dp[201][201];
    int m, n;

    int f(int row, int col, vector<vector<int>>& dungeon) {
       
        if (row >= m || col >= n)
            return INT_MAX;

        if (row == m-1 && col == n-1)
            return max(1, 1 - dungeon[row][col]);

        if (dp[row][col] != -1)
            return dp[row][col];

        int right = f(row, col+1, dungeon);
        int down  = f(row+1, col, dungeon);

        int need = min(right, down);
        return dp[row][col] = max(1, need - dungeon[row][col]);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        m = dungeon.size();
        n = dungeon[0].size();
        return f(0, 0, dungeon);
    }
};
