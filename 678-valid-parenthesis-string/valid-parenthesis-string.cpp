class Solution {
public:
   

    bool check(int index, int op_bra, string &s, vector<vector<int>> &dp) {

        if(op_bra<0)
        return false;
        if (index == s.size()) {
            return op_bra == 0;
        }


            
        if (dp[index][op_bra] != -1)
            return dp[index][op_bra];

            
        bool ans = false;

        if (s[index] == '(') {
            ans = check(index + 1, op_bra + 1, s, dp);
        } else if (s[index] == ')') {
            ans = check(index + 1, op_bra - 1, s, dp);
        } else {
            bool a = check(index + 1,op_bra + 1, s, dp);
            bool b = check(index + 1, op_bra - 1, s, dp);
            bool c = check(index + 1, op_bra, s, dp);
            ans = a | b | c;
        }

        return dp[index][op_bra] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return check(0, 0, s, dp);
    }
};
