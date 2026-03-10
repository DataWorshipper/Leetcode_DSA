typedef long long ll;
const int MOD=1e9+7;
class Solution {
public:
ll dp[2001][1002];
ll pref[2001][1002];
bool vis[2001][1002];
ll getpref(ll index,ll x,vector<int>& nums)
{
    if(x<0)
    return 0;
      if(vis[index][x])
        return pref[index][x];

       vis[index][x] = true;
       pref[index][x]=getpref(index,x-1,nums)+f(index,x,nums);
       return pref[index][x];
}
ll f(ll index,ll prev1,vector<int>& nums)
{
    ll n=nums.size();
    if(index>=n)
    {
        return 1;
    }
    if(dp[index][prev1+1]!=-1)
    return dp[index][prev1+1];
    ll ans=0;
    if(prev1==-1)
    {
        ans=getpref(index+1,nums[0],nums);
    }
    else
    {

       int limit=min(prev1,nums[index]-nums[index-1]+prev1);
       limit=min(limit,nums[index]);
       if(limit>=0)
       ans=getpref(index+1,limit,nums);
    }

    return dp[index][prev1+1]=ans%MOD;
}
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
         memset(vis,false,sizeof(vis));
           memset(pref,0,sizeof(pref));
        return f(0,-1,nums);
    }
};