class Solution {
public:
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;

    ll binexp(ll a, ll b) {
        ll res = 1;
        a %= MOD;

        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int maxNiceDivisors(int primeFactors) {
        ll c = primeFactors;

        if (c <= 3) return c;

        if (c % 3 == 0)
            return (int)binexp(3, c / 3);

        if (c % 3 == 1)
            return (int)(4LL * binexp(3, c / 3 - 1) % MOD);

        return (int)(2LL * binexp(3, c / 3) % MOD);
    }
};