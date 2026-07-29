class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int modpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int solve(int i, int sum, vector<int>& nums, int k,
              vector<vector<int>>& dp) {
        if (i == nums.size())
            return (sum < k);

        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long ans = solve(i + 1, sum, nums, k, dp);
        if (sum + nums[i] < k)
            ans += solve(i + 1, sum + nums[i], nums, k, dp);

        return dp[i][sum] = ans % MOD;
    }

    int countPartitions(vector<int>& nums, int k) {
        long long total = 0;
        for (int x : nums) total += x;

       
        if (total < 2LL * k)
            return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(k, -1));

        long long bad = solve(0, 0, nums, k, dp);

        long long totalPartitions = modpow(2, nums.size());

        long long ans = (totalPartitions - 2 * bad) % MOD;
        if (ans < 0) ans += MOD;

        return ans;
    }
};