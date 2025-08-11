class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        for (int i = 0; i <= 31; i++) {
            if ((n >> i) & 1) {
                power.push_back(1 << i);
            }
        }

        vector<long long> prefix(power.size());
        prefix[0] = power[0] % MOD;
        for (int i = 1; i < power.size(); i++) {
            prefix[i] = (prefix[i-1] * 1LL * power[i]) % MOD;
        }

        vector<int> ans;
        for (auto &it : queries) {
            int l = it[0], r = it[1];
            if (l == 0) {
                ans.push_back(prefix[r]);
            } else {
                long long numerator = prefix[r];
                long long denominator_inv = modPow(prefix[l-1], MOD - 2); 
                ans.push_back((numerator * denominator_inv) % MOD);
            }
        }
        return ans;
    }
};
