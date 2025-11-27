class Solution {
public:
const int MOD=1e9+7;
int dp[2001][52][52];
int f(int index,int prev1,int prev2,vector<int>& nums)
{
    if(index==nums.size())
    {
        return 1;
    }

    if(dp[index][prev1][prev2]!=-1)
    return dp[index][prev1][prev2];
    int ans=0;
    for(int i=0;i<=nums[index];i++)
    {
        int d1=i;
        int d2=nums[index]-i;
        if(d1>=prev1 &&d2<=prev2)
        {
            ans=(ans+f(index+1,d1,d2,nums))%MOD;
        }
    }

    return dp[index][prev1][prev2]=ans%MOD;
}
    int countOfPairs(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return f(0,0,51,nums);


    }
};