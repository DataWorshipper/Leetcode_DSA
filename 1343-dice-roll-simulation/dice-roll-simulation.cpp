class Solution {
public:
int dp[5001][7][16];
const int MOD=1e9+7;
int f(int index,int prev,int occur,int n, vector<int>& rollMax)
{
    int ans=0;
    if(index==n)
    return 1;

    if(dp[index][prev][occur]!=-1)
    return dp[index][prev][occur];

   

    for(int i=1;i<=6;i++)
    {
        if(i!=prev)
        {
            ans=(ans+f(index+1,i,1,n,rollMax))%MOD;
        }
        else
        {
            if(occur<rollMax[prev-1])
            ans=(ans+f(index+1,prev,occur+1,n,rollMax))%MOD;
        }


    }

    return dp[index][prev][occur]=ans%MOD;
}
    int dieSimulator(int n, vector<int>& rollMax) {
        
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,n,rollMax);

    }
};