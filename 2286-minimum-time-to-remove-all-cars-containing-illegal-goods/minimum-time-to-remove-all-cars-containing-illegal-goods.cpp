typedef long long ll;

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();

        vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            dp[i][0] = min({
                dp[i + 1][0] + 1,
                dp[i + 1][1] + 1,
                dp[i + 1][2] + 1
            });

            if(s[i] == '1')
            {
                dp[i][1] = min(
                    dp[i + 1][1] + 2,
                    dp[i + 1][2] + 2
                );
            }
            else
            {
                dp[i][1] = min(
                    dp[i + 1][1],
                    dp[i + 1][2]
                );
            }

            dp[i][2] = dp[i + 1][2] + 1;
        }

        return min({dp[0][0], dp[0][1], dp[0][2]});
    }
};