class Solution {
public:
    const int mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp >>= 1;
        }

        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int j = upper_bound(nums.begin() + i, nums.end(),
                                target - nums[i])
                    - nums.begin() - 1;

            if(j >= i) {
                ans = (ans + modPow(2, j - i)) % mod;
            }
        }

        return ans;
    }
};
