class Solution {
public:
int getcost(int l,int r,string &s)
{   
    int cnt=0;
    while(l<r)
    {
        if(s[l]!=s[r])
        cnt++;
        
        l++;
        r--;

    }
    return cnt;
}
    int palindromePartition(string s, int k1) {
         int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(k1+1, INF));
      for(int i=0;i<n;i++)
      {
        dp[i][1]=getcost(0,i,s);
      }

        for(int k=2;k<=k1;k++)
        {
            for(int i=0;i<s.size();i++)
            {
                for(int j=0;j<i;j++)
                {
                    dp[i][k]=min(dp[i][k],dp[j][k-1]+getcost(j+1,i,s));
                }
            }
        }
        return dp[s.size()-1][k1];

    }
};