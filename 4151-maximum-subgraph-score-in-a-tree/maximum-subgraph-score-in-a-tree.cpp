typedef long long ll;
class Solution {
public:
void dfs1(int node,int par,vector<int>&dp,vector<int>&good,vector<vector<int>>&adj)
{   
    dp[node]=(good[node]==1)?1:-1;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            dfs1(it,node,dp,good,adj);
            dp[node]+=max(0,dp[it]);
        }
    }
}
void dfs2(int node,int par,vector<int>&dp,vector<int>&good,vector<vector<int>>&adj)
{   
    
    for(auto it:adj[node])
    {
        if(it!=par)
        {      
            int x=dp[node]-max(dp[it],0);
            dp[it]+=max(0,x);
            dfs2(it,node,dp,good,adj);
        }
    }
}

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<int>dp(n,0);

        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1(0,-1,dp,good,adj);
        dfs2(0,-1,dp,good,adj);
        return dp;


    }
};