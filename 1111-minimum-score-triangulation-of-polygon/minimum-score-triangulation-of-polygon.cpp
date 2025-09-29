class Solution {
public:

int tri(int i,int j,vector<int>& values,vector<vector<int>>&dp)
{
    if(j-i<2)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int c=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        c=min(c,tri(i,k,values,dp)+tri(k,j,values,dp)+values[i]*values[k]*values[j]);
    }
    return dp[i][j]=c;
}
    int minScoreTriangulation(vector<int>& values) {
        
        int  n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return tri(0,n-1,values,dp);
    }
};