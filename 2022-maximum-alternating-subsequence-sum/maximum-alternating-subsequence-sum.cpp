class Solution {
public:
    long long dp[100005][2];

    long long solve(int i, int p, vector<int>& nums) {
        if (i == nums.size()) return 0;

        if (dp[i][p] != -1) return dp[i][p];

        long long notTake = solve(i+1, p, nums);

        long long take;
        if (p == 0)
            take = nums[i] + solve(i+1, 1, nums);
        else
            take = -nums[i] + solve(i+1, 0, nums);

        return dp[i][p] = max(notTake, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums);
    }
};