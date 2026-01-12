class Solution {
public:
    const int MOD = 1e9+7;
    int dp[501][501];

    int f(int index, int step, int steps, int arrLen) {
        if(index < 0 || index >= arrLen) return 0;
        if(index > steps/2) return 0;  
        if(step == steps) return index == 0;

        if(dp[index][step] != -1) return dp[index][step];

        long long ans = 0;
        ans = (ans + f(index, step+1, steps, arrLen)) % MOD;  
        ans = (ans + f(index+1, step+1, steps, arrLen)) % MOD;   
        ans = (ans + f(index-1, step+1, steps, arrLen)) % MOD;  

        return dp[index][step] = ans;
    }

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, steps, arrLen);
    }
};
