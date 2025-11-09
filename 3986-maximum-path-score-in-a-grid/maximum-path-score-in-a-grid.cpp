typedef long long ll;

ll f(int i,int j,int cost,vector<vector<int>>& grid, int k,
     vector<vector<vector<ll>>>& dp)
{
    int m=grid.size();
    int n=grid[0].size();

    int v = grid[i][j];
    int score = v;
    int addcost = (v==2?1:v);

    cost += addcost;
    if(cost > k) return -1;

    if(i==m-1 && j==n-1)
        return score;

    if(dp[i][j][cost] != LLONG_MIN)
        return dp[i][j][cost];

    ll ans = -1;

    if(j+1 < n)
    {
        ll right = f(i, j+1, cost, grid, k, dp);
        if(right != -1) ans = max(ans, score + right);
    }

    if(i+1 < m)
    {
        ll down = f(i+1, j, cost, grid, k, dp);
        if(down != -1) ans = max(ans, score + down);
    }

    return dp[i][j][cost] = ans;
}

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(k+1, LLONG_MIN)));

        return (int)f(0, 0, 0, grid, k, dp);
    }
};
