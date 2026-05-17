class Solution {
public:
    using ull = unsigned long long;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const ull BASE = 911382323;

        vector<ull> pw(n + 1, 1), pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * BASE;
        }

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * BASE + (ull)(nums[i] + 1000000007LL);
        }

        auto getHash = [&](int l, int r) {
            return pref[r + 1] - pref[l] * pw[r - l + 1];
        };

        int lo = 1, hi = n;
        int ans = n;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            unordered_map<ull, int> mp;

            int l = 0;

            for (int r = 0; r < n; r++) {
                if (r - l + 1 == mid) {
                    ull h = getHash(l, r);
                    mp[h]++;
                    l++;
                }
            }

            bool ok = false;

            for (auto &[h, cnt] : mp) {
                if (cnt == 1) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};