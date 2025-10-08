typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll dp[20005][26]; 

    ll f(ll index, char prev, int n, vector<char>& arr) {
        if (index == n)
            return 1;

        int pi = (prev == '#') ? 25 : (prev - 'a');
        if (dp[index][pi] != -1)
            return dp[index][pi];

        ll ans = 0;
        for (ll j = 0; j < arr.size(); j++) {
            char c = arr[j];

            if (prev == '#') {
                ans = (ans + f(index + 1, c, n, arr)) % MOD;
            }
            else if (prev == 'a' && c == 'e') {
                ans = (ans + f(index + 1, c, n, arr)) % MOD;
            }
            else if (prev == 'e' && (c == 'a' || c == 'i')) {
                ans = (ans + f(index + 1, c, n, arr)) % MOD;
            }
            else if (prev == 'i' && (c != 'i')) {
                ans = (ans + f(index + 1, c, n, arr)) % MOD;
            }
            else if (prev == 'o' && (c == 'i' || c == 'u')) {
                ans = (ans + f(index + 1, c, n, arr)) % MOD;
            }
            else if (prev == 'u' && c == 'a') {
                ans = (ans + f(index + 1, c, n, arr)) % MOD;
            }
        }

        return dp[index][pi] = ans % MOD;
    }

    int countVowelPermutation(int n) {
        vector<char> arr = {'a', 'e', 'i', 'o', 'u'};
        memset(dp, -1, sizeof(dp));
        return (int)(f(0, '#', n, arr) % MOD);
    }
};
