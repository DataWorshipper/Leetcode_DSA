typedef long long ll;

class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        ll n = s.size();
        ll c0 = 0;
        ll c1 = 0;

        for (ll i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;

            if (s[i] == '0' && t[i] == '1')
                c0++;
            else
                c1++;
        }

        ll res1 = 1LL * flipCost * (c0 + c1);

        ll mn = min(c0, c1);
        ll res2 = 1LL * swapCost * mn +
                  1LL * flipCost * (max(c0, c1) - mn);

        ll d = llabs(c0 - c1) / 2;
        ll cross = 1LL * crossCost * d;

        ll mn1 = min(c0, c1);
        ll mn2 = max(c0, c1);

        mn1 += d;
        mn2 -= d;

        ll swp = 1LL * swapCost * mn1;

        mn2 -= mn1;

        ll flip = 1LL * flipCost * mn2;

        ll res3 = flip + swp + cross;

        return min({res1, res2, res3});
    }
};