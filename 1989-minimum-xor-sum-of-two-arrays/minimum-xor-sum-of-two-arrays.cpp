typedef long long ll;
class Solution {
public:
ll dp[15][1<<14];
ll f(int index,vector<int>& nums1, vector<int>& nums2,int mask)
{
    if(index==nums1.size())
    {
        return 0;
    }
    if(dp[index][mask]!=-1)
    return  dp[index][mask];
    ll ans=LLONG_MAX;
    for(int i=0;i<nums2.size();i++)
    {
        if(!(mask&(1<<i)))
        {
           ans=min((ll)ans,(nums1[index]^nums2[i])+f(index+1,nums1,nums2,mask|(1<<i)));
        }
    }
    return dp[index][mask]=ans;
}
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {

            int mask=0;
            int index=0;
            memset(dp,-1,sizeof(dp));
            return (int)f(0,nums1,nums2,0);
    }
};