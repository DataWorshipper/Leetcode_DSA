class Solution {
public:
    int memo[71][4901];

    int dp(int i, int sum, vector<vector<int>>& mat, int target) {
        if (i == mat.size())
            return abs(sum - target);

        if (memo[i][sum] != -1)
            return memo[i][sum];

        int ans = INT_MAX;

        for (int x : mat[i]) {
            ans = min(ans, dp(i + 1, sum + x, mat, target));
        }

        return memo[i][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, mat, target);
    }
};