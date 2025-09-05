typedef long long ll;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            ll res = (ll)num1 - (ll)k * num2;
            if (res < 0) break;
            int bits = __builtin_popcountll(res);
            if (bits <= k && k <= res) {
                return k;
            }
        }
        return -1;
    }
};
