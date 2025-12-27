class Solution {
    const int MOD = 1e9 + 7;
    int dp[101][101][101];

public:
    int f(int index, int curr_profit, int curr_group,
          int minProfit, int n,
          vector<int>& group, vector<int>& profit) {

        if (index == group.size())
            return curr_profit >= minProfit;

        curr_profit = min(curr_profit, minProfit);

        if (dp[index][curr_profit][curr_group] != -1)
            return dp[index][curr_profit][curr_group];

        long long ans = 0;

    
        ans += f(index + 1, curr_profit, curr_group,
                 minProfit, n, group, profit);

       
        if (curr_group + group[index] <= n) {
            ans += f(index + 1,
                     curr_profit + profit[index],
                     curr_group + group[index],
                     minProfit, n, group, profit);
        }

        return dp[index][curr_profit][curr_group] = ans % MOD;
    }

    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, minProfit, n, group, profit);
    }
};
