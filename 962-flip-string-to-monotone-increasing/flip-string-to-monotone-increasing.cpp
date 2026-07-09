class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        vector<int> pref1(n + 1, 0), pref0(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref1[i + 1] = pref1[i] + (s[i] == '1');
            pref0[i + 1] = pref0[i] + (s[i] == '0');
        }

        int ans = n;

        for (int i = 0; i <= n; i++) {
            int leftOnes = pref1[i];
            int rightZeros = pref0[n] - pref0[i];
            ans = min(ans, leftOnes + rightZeros);
        }

        return ans;
    }
};