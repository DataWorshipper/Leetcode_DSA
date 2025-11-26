class Solution {
public:
const int MOD=1e9+7;
vector<vector<vector<int>>>dp;
int f(int i,int j,int sum_mod,vector<vector<int>>& grid, int k)
{   
    int m=grid.size();
    int n=grid[0].size();

    if(i==m-1 &&j==n-1)
    {
        if(sum_mod%k==0)
        return 1;
        else
        return 0;
    }

    int ans=0;
    if(dp[i][j][sum_mod]!=-1)
    return dp[i][j][sum_mod];

    if(i+1<m)
    {   
        int new_mod=(sum_mod+grid[i+1][j])%k;
        ans=(ans+f(i+1,j,new_mod,grid,k))%MOD;
    }
    if(j+1<n)
    {
        int new_mod=(sum_mod+grid[i][j+1])%k;
        ans=(ans+f(i,j+1,new_mod,grid,k))%MOD;
    }

    return dp[i][j][sum_mod]=(ans)%MOD;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
          dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
          int start_mod=grid[0][0]%k;
          return f(0,0,start_mod,grid,k);

    }
};