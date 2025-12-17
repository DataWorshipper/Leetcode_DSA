typedef long long ll;
class Solution {
    ll dp[1002][1002][3];
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        
        memset(dp,-1,sizeof(dp));
        for(int t=0;t<=k;t++)
        {
            dp[0][t][0]=0;
            dp[0][t][1]=-prices[0];
            dp[0][t][2]=prices[0];

        }

        for(int i=1;i<prices.size();i++)
        {
            for(int t=0;t<=k;t++)
            {
               dp[i][t][1]=max(dp[i-1][t][1],dp[i-1][t][0]-prices[i]);
               dp[i][t][2]=max(dp[i-1][t][2],dp[i-1][t][0]+prices[i]);
               if(t==0)
               dp[i][t][0]=dp[i-1][t][0];
                else 
                dp[i][t][0]=max({dp[i-1][t][0],dp[i-1][t-1][1]+prices[i],dp[i-1][t-1][2]-prices[i]});
           }
        }

        return dp[n-1][k][0];
        

    }
};