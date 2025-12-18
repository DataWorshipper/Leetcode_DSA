class Solution {
public:
int cost(int l,int r,vector<int>&cuts,vector<vector<int>>&dp)
{
    if(r-l<=1)
    return 0;
    if(dp[l][r]!=-1)
    return dp[l][r];
    int c=INT_MAX;
    for(int i=l+1;i<r;i++)
    {
        c=min(c,cost(l,i,cuts,dp)+cost(i,r,cuts,dp)+cuts[r]-cuts[l]);
    }
    return dp[l][r]=c;
}
    int minCost(int n, vector<int>& cuts) {
        
      cuts.push_back(0);
      cuts.push_back(n);
      sort(cuts.begin(),cuts.end());
      vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
   int m=cuts.size();

    return cost(0,m-1,cuts,dp);

    }
};