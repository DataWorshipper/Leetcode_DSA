class Solution {
public:
    long long MOD = 1e9 + 7;

    int maxProfit(vector<int>& inventory, int orders) {
        long long lo = 1;
        long long hi = *max_element(inventory.begin(), inventory.end());

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            long long cnt = 0;
            for (int x : inventory)
                cnt += max(0LL, (long long)x - mid + 1);

            if (cnt >= orders)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        long long k = hi;

        long long sold = 0;
        long long ans = 0;

        for (int x : inventory) {
            if (x >= k) {
                long long num = x - k + 1;
                sold += num;

                long long sum =
                    (1LL * x * (x + 1) / 2) -
                    (1LL * (k - 1) * k / 2);

                ans = (ans + sum) % MOD;
            }
        }

        long long extra = sold - orders;
        ans = (ans - (extra * k) % MOD + MOD) % MOD;

        return ans;
    }
};