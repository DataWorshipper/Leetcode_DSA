typedef long long ll;
class Solution {
public:
const int MOD=1e9+7;
ll dp[41][1<<10];
ll f(ll index,ll mask, map<int,vector<int>>&mpp,ll n)
{   
    if(mask==((1<<n)-1))
    return 1;
    if(index>40)
    return 0;
    if(dp[index][mask]!=-1)
    return dp[index][mask];
    ll ans=f(index+1,mask,mpp,n);
    
   
        for(int i=0;i<mpp[index].size();i++)
        {
            if(!(mask&(1<<mpp[index][i])))
            {
                ans=(ans+f(index+1,mask|(1<<mpp[index][i]),mpp,n))%MOD;
            }
        }
    
        
    

    return dp[index][mask]=ans;
}
    int numberWays(vector<vector<int>>& hats) {
        map<int,vector<int>>mpp;
        for(int i=0;i<hats.size();i++)
        {
            int person=i;
            for(int j=0;j<hats[i].size();j++)
            {
                mpp[hats[i][j]].push_back(person);
            }
        }

        int n=hats.size();
        memset(dp,-1,sizeof(dp));
        return (int)f(0,0,mpp,n);
    }
};