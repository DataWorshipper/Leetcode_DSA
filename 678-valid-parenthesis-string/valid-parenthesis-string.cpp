 class Solution {
public:
    int offset = 102;

    bool check(int index, int bal, string &s, vector<vector<int>> &dp) {
        if(bal<0)
        return false;
        if (index == s.size()) {
            return bal == 0;
        }


            
        if (dp[index][bal + offset] != -1)
            return dp[index][bal + offset];

        bool ans = false;

        if (s[index] == '(') {
            ans = check(index + 1, bal + 1, s, dp);
        } else if (s[index] == ')') {
            ans = check(index + 1, bal - 1, s, dp);
        } else {
            bool a = check(index + 1, bal + 1, s, dp);
            bool b = check(index + 1, bal - 1, s, dp);
            bool c = check(index + 1, bal, s, dp);
            ans = a | b | c;
        }

        return dp[index][bal + offset] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1 + offset, -1));
        return check(0, 0, s, dp);
    }
};