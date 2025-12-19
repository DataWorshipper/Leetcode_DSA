class Solution {
    public:
    int m=0;
    void dfs(int n, vector<vector<pair<int,int>>>&adj,vector<int>&vis,int node)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it.first])
            {m+=it.second;
            dfs(n,adj,vis,it.first);
            }


        }
    }
public:

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
             adj[v].push_back({u,0});
        }
            vector<int>vis(n,0);
            dfs(n,adj,vis,0);
            return abs(m);

    }
};