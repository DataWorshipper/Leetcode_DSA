
class Solution {
private:
    using ll = long long;

    static constexpr ll MOD1 = 1000000007LL;
    static constexpr ll MOD2 = 1000000009LL;
    static constexpr ll P = 911382323LL;

    int n;
    vector<ll> pref1, pref2, rev1, rev2;
    vector<ll> p1, p2, pref3;

    ll getHash(const vector<ll>& pref,
               const vector<ll>& powers,
               int l, int r, ll mod) {
        return (pref[r + 1] - pref[l] * powers[r - l + 1] % mod + mod) % mod;
    }

    bool isPalindrome(int l, int r) {
        int l2 = n - 1 - r;
        int r2 = n - 1 - l;

        return getHash(pref1, p1, l, r, MOD1) ==
                   getHash(rev1, p1, l2, r2, MOD1)
            && getHash(pref2, p2, l, r, MOD2) ==
                   getHash(rev2, p2, l2, r2, MOD2);
    }

    int palRadiusOdd(int i) {
        int low = 0;
        int high = min(i, n - 1 - i);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPalindrome(i - mid, i + mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int palRadiusEven(int i) {
        int low = 0;
        int high = min(i, n - i);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid == 0 || isPalindrome(i - mid, i + mid - 1)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

public:
    long long getSum(vector<int>& nums) {
        n = nums.size();

        pref1.assign(n + 1, 0);
        pref2.assign(n + 1, 0);
        rev1.assign(n + 1, 0);
        rev2.assign(n + 1, 0);

        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        pref3.assign(n + 1, 0);

        vector<int> rev(nums.rbegin(), nums.rend());

        for (int i = 0; i < n; ++i) {
            pref1[i + 1] = (pref1[i] * P + nums[i]) % MOD1;
            pref2[i + 1] = (pref2[i] * P + nums[i]) % MOD2;

            rev1[i + 1] = (rev1[i] * P + rev[i]) % MOD1;
            rev2[i + 1] = (rev2[i] * P + rev[i]) % MOD2;

            p1[i + 1] = p1[i] * P % MOD1;
            p2[i + 1] = p2[i] * P % MOD2;

            pref3[i + 1] = pref3[i] + nums[i];
        }

        long long ansSum = 0;

        for (int i = 0; i < n; ++i) {
            int radius = palRadiusOdd(i);

            long long total =
                pref3[i + radius + 1] - pref3[i - radius];

            ansSum = max(ansSum, total);
        }

        for (int i = 1; i < n; ++i) {
            int radius = palRadiusEven(i);

            if (radius > 0) {
                long long total =
                    pref3[i + radius] - pref3[i - radius];

                ansSum = max(ansSum, total);
            }
        }

        return ansSum;
    }
};
