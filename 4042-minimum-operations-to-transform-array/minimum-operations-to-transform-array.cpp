

#define ll long long
#define v vector

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();

        v<ll> diff(n, 0);

        diff[0] = abs(nums1[0] - nums2[0]);

        for (ll i = 1; i < n; i++) {
            diff[i] = diff[i - 1] + abs(nums1[i] - nums2[i]);
        }

        ll c = nums2[n];
        ll ans = LLONG_MAX;

        for (ll i = 0; i < n; i++) {
            ll ops1 = (i > 0) ? diff[i - 1] : 0;
            ll ops2 = diff[n - 1] - diff[i];

            ll option1 = abs(nums1[i] - nums2[i])
                       + abs(nums1[i] - c)
                       + 1;

            ll option2 = abs(nums1[i] - nums2[i])
                       + 1
                       + abs(nums2[i] - c);

            ll option3 = abs(nums1[i] - c)
                       + 1
                       + abs(c - nums2[i]);

            ll extra = min({option1, option2, option3});

            ans = min(ans, ops1 + ops2 + extra);
        }

        return ans;
    }
};