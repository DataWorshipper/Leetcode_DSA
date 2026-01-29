typedef long long ll;
class Solution {
public:
ll dp[8][1<<14];
ll f(ll ops,ll mask,vector<int>& nums,int n)
{
    if(ops>n)
    {
      return 0;
    }

    if(dp[ops][mask]!=-1)
    return dp[ops][mask];
ll ans=LLONG_MIN;
    for(int i=0;i<2*n;i++)
    {
        for(int j=i+1;j<2*n;j++)
        {   
            if (!(mask & (1<<i))) continue;
if (!(mask & (1<<j))) continue;

            ll score = ops*gcd(nums[i],nums[j]);
            ll new_mask=mask^(1<<i)^(1<<j);
            ans=max(ans,score+f(ops+1,new_mask,nums,n));
        }
    }
    return dp[ops][mask]=ans;
}
    int maxScore(vector<int>& nums) {
        ll x=nums.size();
        ll n=x/2;
        ll mask=(1<<x)-1;
        memset(dp,-1,sizeof(dp));
        return f(1,mask,nums,n);
    }
};