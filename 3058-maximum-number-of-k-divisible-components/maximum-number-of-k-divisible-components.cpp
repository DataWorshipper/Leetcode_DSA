class Solution {
public:
int ans=0;
long long dfs(vector<vector<int>>&adj, vector<int>& values, int k,int node,int parent)
{
    long long sum=values[node];
    for(auto it:adj[node])
    {
        if(it==parent)
        continue;
        sum+=dfs(adj,values,k,it,node);}
        if(sum%k==0)
        {
            ans++;
            return 0;
        }
        return sum;
        
    
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj,values,k,0,-1);
        return ans;
    }
};