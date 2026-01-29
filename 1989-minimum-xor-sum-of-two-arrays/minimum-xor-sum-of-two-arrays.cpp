typedef long long ll;

class Solution {
public:
    ll dp[15][1 << 14];

    ll f(int index, vector<int>& nums1, vector<int>& nums2, int mask) {
        if (index == nums2.size()) {
            return 0;
        }

        if (dp[index][mask] != -1)
            return dp[index][mask];

        ll ans = LLONG_MAX;

        for (int i = 0; i < nums1.size(); i++) {
            if (!(mask & (1 << i))) { 
                ans = min(ans,
                          (ll)(nums1[i] ^ nums2[index]) +
                          f(index + 1, nums1, nums2, mask | (1 << i)));
            }
        }

        return dp[index][mask] = ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return (int)f(0, nums1, nums2, 0);
    }
};
