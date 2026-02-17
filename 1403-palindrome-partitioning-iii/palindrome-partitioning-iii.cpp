class Solution {
public:
    int getcost(int l, int r, string &s) {
        int cnt = 0;
        while (l < r) {
            if (s[l] != s[r]) cnt++;
            l++;
            r--;
        }
        return cnt;
    }

    int palindromePartition(string s, int k1) {
        int n = s.size();
        const int INF = 1e9;

   
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int r = 0; r < n; r++) {
            for (int l = 0; l <= r; l++) {
                cost[l][r] = getcost(l, r, s);
            }
        }

       
        vector<vector<int>> dp(n, vector<int>(k1+1, INF));

      
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
        }

        for (int k = 2; k <= k1; k++) {
            for (int i = 0; i < n; i++) {
                if (k > i + 1) continue;

                for (int j = 0; j < i; j++) {
                    if (dp[j][k-1] == INF) continue;
                    dp[i][k] = min(dp[i][k],
                                   dp[j][k-1] + cost[j+1][i]);
                }
            }
        }

        return dp[n-1][k1];
    }
};
