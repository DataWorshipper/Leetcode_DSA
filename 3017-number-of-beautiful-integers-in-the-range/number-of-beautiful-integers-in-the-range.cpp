class Solution {
public:
    int dp[11][2][22][2][22]; 

    int solve(string &s, int index, int tight, int diff, int valid, int rem, int k) {
        if(index == s.size()) {
            if(valid == 1 && rem == 0 && diff == 0)
                return 1;
            else
                return 0;
        }

        if(dp[index][tight][diff + 11][valid][rem] != -1)
            return dp[index][tight][diff + 11][valid][rem];

        int limit;
        if(tight == 1)
            limit = s[index] - '0';
        else
            limit = 9;

        int ans = 0;
        for(int d = 0; d <= limit; d++) {
            int newtight = tight & (d == s[index] - '0');

            if(valid == 0 && d == 0) {
                ans += solve(s, index + 1, newtight, diff, 0, rem, k);
            }
            else if(valid == 0 && d > 0) {
                int new_rem = (rem * 10 + d) % k;
                int new_diff = (d % 2 == 0) ? diff + 1 : diff - 1;
                ans += solve(s, index + 1, newtight, new_diff, 1, new_rem, k);
            }
            else {
                int new_rem = (rem * 10 + d) % k;
                int new_diff = (d % 2 == 0) ? diff + 1 : diff - 1;
                ans += solve(s, index + 1, newtight, new_diff, 1, new_rem, k);
            }
        }

        return dp[index][tight][diff + 11][valid][rem] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l = to_string(low - 1);
        string r = to_string(high);

        memset(dp, -1, sizeof(dp));
        __int128 l1 = solve(l, 0, 1, 0, 0, 0, k);

        memset(dp, -1, sizeof(dp));
        __int128 r1 = solve(r, 0, 1, 0, 0, 0, k);

        return r1 - l1;
    }
};