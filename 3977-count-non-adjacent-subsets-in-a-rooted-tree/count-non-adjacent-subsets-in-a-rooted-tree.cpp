class Solution {
public:
    static long long dp[1000][2][100];

    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = parent.size();

        memset(dp, 0, sizeof(dp));

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        function<void(int, int)> dfs = [&](int node, int par) {
            dp[node][0][0] = 1;
            dp[node][1][nums[node] % k] = 1;

            for (int child : adj[node]) {
                if (child == par)
                    continue;

                dfs(child, node);

                long long ndp[2][100] = {};

                for (int r1 = 0; r1 < k; r1++) {
                    for (int r2 = 0; r2 < k; r2++) {
                        int rem = (r1 + r2) % k;

                        ndp[0][rem] +=
                            dp[node][0][r1] *
                            (dp[child][0][r2] + dp[child][1][r2]);

                        ndp[1][rem] +=
                            dp[node][1][r1] *
                            dp[child][0][r2];

                        ndp[0][rem] %= MOD;
                        ndp[1][rem] %= MOD;
                    }
                }

                for (int rem = 0; rem < k; rem++) {
                    dp[node][0][rem] = ndp[0][rem];
                    dp[node][1][rem] = ndp[1][rem];
                }
            }
        };

        dfs(0, -1);

        return (dp[0][0][0] + dp[0][1][0] - 1 + MOD) % MOD;
    }
};

long long Solution::dp[1000][2][100];