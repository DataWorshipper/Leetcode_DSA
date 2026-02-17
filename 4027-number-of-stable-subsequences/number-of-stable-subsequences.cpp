class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    vector<int> nums;
    long long dp[100005][3][3];

    long long solve(int i, int p1, int p2) {
        if(i == n) return 1;

        if(dp[i][p1][p2] != -1)
            return dp[i][p1][p2];

        long long ans = 0;

     
        ans = solve(i+1, p1, p2) % MOD;

        int cur = nums[i] % 2;

     
        bool canTake = true;

        if(p1 != 2 && p2 != 2) {
            if(p1 == p2 && p1 == cur)
                canTake = false;
        }

        if(canTake) {
            ans = (ans + solve(i+1, cur, p1)) % MOD;
        }

        return dp[i][p1][p2] = ans;
    }

    int countStableSubsequences(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 2, 2)-1;
    }
};
