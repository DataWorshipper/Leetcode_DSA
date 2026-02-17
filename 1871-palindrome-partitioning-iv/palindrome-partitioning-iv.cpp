class Solution {
public:
bool isPalindrome(int l, int r, const string &s) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(4,false));

        for(int i=0;i<n;i++)
        {
            dp[i][1]=isPalindrome(0,i,s);
        }

        for(int k=2;k<=3;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    dp[i][k]=(dp[i][k])|(dp[j][k-1]&&(isPalindrome(j+1,i,s)));
                }
            }
        }

        return dp[n-1][3];
    }
};