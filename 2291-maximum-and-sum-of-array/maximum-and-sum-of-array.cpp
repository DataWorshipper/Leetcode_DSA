typedef long long ll;

class Solution {
public:
    ll dp[19][1 << 18];

    ll f(int pos, int mask, vector<int>& nums, vector<int>& slots) {
        if (pos == slots.size())
            return 0;

        if (dp[pos][mask] != -1)
            return dp[pos][mask];

        ll ans = f(pos + 1, mask, nums, slots);

        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) continue;

            ans = max(
                ans,
                (ll)(nums[i] & slots[pos]) +
                f(pos + 1,
                  mask | (1 << i),
                  nums,
                  slots)
            );
        }

        return dp[pos][mask] = ans;
    }

    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> slots;

        for (int i = 1; i <= numSlots; i++) {
            slots.push_back(i);
            slots.push_back(i);
        }

        memset(dp, -1, sizeof(dp));

        return f(0, 0, nums, slots);
    }
};