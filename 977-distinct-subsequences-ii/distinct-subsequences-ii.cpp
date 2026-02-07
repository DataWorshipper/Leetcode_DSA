class Solution {
public:
const int MOD = 1e9+7;

int distinctSubseqII(string s) {

    int n = s.size();
    vector<int> last(26, -1);
    vector<int> dp(n, 0);

    dp[0] = 2;
    last[s[0]-'a'] = 0;    

    for(int i=1;i<n;i++)
    {
        dp[i] = (2LL * dp[i-1]) % MOD;

        int a = s[i]-'a';

        if(last[a] != -1)
        {
            if(last[a] > 0)
                dp[i] = (dp[i] - dp[last[a]-1] + MOD) % MOD;
            else
                dp[i] = (dp[i] - 1 + MOD) % MOD;   
        }

        last[a] = i;
    }

    return (dp[n-1] - 1 + MOD) % MOD;
}
};
