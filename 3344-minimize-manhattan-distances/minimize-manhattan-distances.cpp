typedef long long ll;

class Solution {
public:

    vector<ll> f1(const vector<vector<int>>& points)
    {
        vector<ll> a(points.size());
        for (ll i = 0; i < (ll)points.size(); i++) {
            ll x = points[i][0];
            ll y = points[i][1];
            a[i] = x + y;
        }
        return a;
    }

    vector<ll> f2(const vector<vector<int>>& points)
    {
        vector<ll> a(points.size());
        for (ll i = 0; i < (ll)points.size(); i++) {
            ll x = points[i][0];
            ll y = points[i][1];
            a[i] = x - y;
        }
        return a;
    }

   
    ll ans(vector<ll> s, vector<ll> d, ll idx)
    {
        // erase
        s.erase(s.begin() + idx);
        d.erase(d.begin() + idx);

        sort(s.begin(), s.end());
        sort(d.begin(), d.end());

        if (s.size() == 0) return 0;

        ll a = s.back() - s.front();
        ll b = d.back() - d.front();

        return max(a, b);
    }

    int minimumDistance(vector<vector<int>>& points)
    {
        ll n = points.size();

        ll maxsum = LLONG_MIN, minsum = LLONG_MAX;
        ll maxdiff = LLONG_MIN, mindiff = LLONG_MAX;
        ll maxsumidx = 0, minsumidx = 0, maxdiffidx = 0, mindiffidx = 0;

       
        for (ll i = 0; i < n; i++) {
            ll x = points[i][0];
            ll y = points[i][1];
            ll sum = x + y;
            ll diff = x - y;

            if (sum > maxsum) maxsum = sum, maxsumidx = i;
            if (sum < minsum) minsum = sum, minsumidx = i;

            if (diff > maxdiff) maxdiff = diff, maxdiffidx = i;
            if (diff < mindiff) mindiff = diff, mindiffidx = i;
        }

        vector<ll> s = f1(points);
        vector<ll> d = f2(points);

     
        ll a1 = ans(s, d, maxsumidx);
        ll a2 = ans(s, d, minsumidx);
        ll a3 = ans(s, d, maxdiffidx);
        ll a4 = ans(s, d, mindiffidx);

       
        sort(s.begin(), s.end());
        sort(d.begin(), d.end());
        ll a5 = max(s.back() - s.front(), d.back() - d.front());

        ll answer = min({a1, a2, a3, a4, a5});
        return (int)answer;
    }
};
