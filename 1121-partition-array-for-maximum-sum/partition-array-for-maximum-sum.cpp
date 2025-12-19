class Solution {
public:
    int dp[501];

    int f(int i, vector<int>& arr, int k) {
        if (i == arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int mx = 0;
        int ans = 0;

        for (int len = 1; len <= k && i + len <= arr.size(); len++) {
            mx = max(mx, arr[i + len - 1]);
            ans = max(ans, mx * len + f(i + len, arr, k));
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, arr, k);
    }
};
