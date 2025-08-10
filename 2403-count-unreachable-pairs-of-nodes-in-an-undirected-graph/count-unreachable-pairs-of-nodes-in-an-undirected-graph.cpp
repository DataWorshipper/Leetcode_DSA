class Solution {
public:
int c=0;
void dfs(vector<vector<int>>&adj,int node,vector<int>&vis)
{
    vis[node]=1;
    c++;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(adj,it,vis);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>count;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                count.push_back(c);
                c=0;

            }
        }

        long long  sum=accumulate(count.begin(),count.end(),0LL);
        int p=0;
        long long  ans=0;
        for(int i=0;i<count.size();i++)
        {
            p+=count[i];
            ans+=(long long)(count[i]*(sum-p));
        }
        return ans;
    }
};