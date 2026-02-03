class Solution {
public:
int dp[1001][1001];
int rec(int i,int x,vector<int>& nums, int k,  map<int,vector<int>>&mpp)
{
    if(dp[i][x]!=-1)
    {
        return dp[i][x];
    }
    int ans=2;
    auto it=lower_bound(mpp[nums[i]%k].begin(),mpp[nums[i]%k].end(),x);
   
    if(it!=mpp[nums[i]%k].begin())
    {       
        it--;
          int y=*it;
        
        ans=max(ans,1+rec(x,y,nums,k,mpp));
    }
    return dp[i][x]=ans;


}
    int maximumLength(vector<int>& nums, int k) {
        map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]%k].push_back(i);
        }
    memset(dp,-1,sizeof(dp));
    int ans=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                for(int j=0;j<i;j++)
                {
                    ans=max(ans,rec(i,j,nums,k,mpp));
                }
            }
            return ans;

    }
};