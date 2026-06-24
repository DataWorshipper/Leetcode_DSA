typedef long long ll;

class Solution {
public:

ll dp[1 << 16];

ll f2(ll mask,
      vector<int>& nums,
      ll len,
      vector<ll>& cost)
{
    if(mask == 0)
        return 0;

    if(dp[mask] != -1)
        return dp[mask];

    ll ans = LLONG_MAX;

    for(ll sub = mask; sub; sub = (sub - 1) & mask)
    {
        if(cost[sub] == -1)
            continue;

        ll nxt = f2(mask ^ sub, nums, len, cost);

        if(nxt != LLONG_MAX)
        {
            ans = min(ans, cost[sub] + nxt);
        }
    }

    return dp[mask] = ans;
}

int minimumIncompatibility(vector<int>& nums, int k) {

    ll n = nums.size();
    ll len = n / k;

    memset(dp, -1, sizeof(dp));

    vector<ll> cost(1 << n, -1);

    for(ll mask = 0; mask < (1 << n); mask++)
    {
        if(__builtin_popcount(mask) != len)
            continue;

        set<ll> s;

        ll mn = LLONG_MAX;
        ll mx = LLONG_MIN;

        bool ok = true;

        for(ll i = 0; i < n; i++)
        {
            if((mask >> i) & 1)
            {
                if(s.count(nums[i]))
                {
                    ok = false;
                    break;
                }

                s.insert(nums[i]);

                mn = min(mn, (ll)nums[i]);
                mx = max(mx, (ll)nums[i]);
            }
        }

        if(ok)
        {
            cost[mask] = mx - mn;
        }
    }

    ll ans = f2((1 << n) - 1, nums, len, cost);

    return (ans == LLONG_MAX ? -1 : ans);
}
};