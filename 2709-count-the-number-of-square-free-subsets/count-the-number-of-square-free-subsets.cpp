class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
    unordered_map<int,int> mpp;

    int getMask(int x) {
        int mask = 0;
        for (int p : primes) {
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            if (cnt > 1) return -1;
            if (cnt == 1) mask |= (1 << mpp[p]);
        }
        return mask;
    }

    int solve(int i, int mask, vector<int>& numMask, vector<vector<int>>& dp) {
        if (i == numMask.size()) return 1;
        if (dp[i][mask] != -1) return dp[i][mask];

        long long ans = solve(i+1, mask, numMask, dp);

        if (numMask[i] != -1 && (mask & numMask[i]) == 0) {
            ans += solve(i+1, mask | numMask[i], numMask, dp);
        }

        return dp[i][mask] = ans % MOD;
    }

    int squareFreeSubsets(vector<int>& nums) {
        for (int i = 0; i < primes.size(); i++) {
            mpp[primes[i]] = i;
        }

        int ones = 0;
        vector<int> numMask;

       for (int x : nums) {
    if (x == 1) {
        ones++;
    } else {
        int m = getMask(x);
       
            numMask.push_back(m); 
        
    }
}

        int n = numMask.size();
        vector<vector<int>> dp(n, vector<int>(1<<10, -1));

        long long ans = solve(0, 0, numMask, dp) - 1;
        if (ans < 0) ans += MOD;

        long long pow2 = 1;
        for (int i = 0; i < ones; i++) {
            pow2 = (pow2 * 2) % MOD;
        }

      

 long long onlyOnes = (pow2 - 1 + MOD) % MOD;
ans = (ans * pow2) % MOD;
ans = (ans + onlyOnes) % MOD;

return ans;
    }
};