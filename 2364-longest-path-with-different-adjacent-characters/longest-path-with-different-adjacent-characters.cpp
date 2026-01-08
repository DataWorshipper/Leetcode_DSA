class Solution {
public:
int ans=1;
int dfs( vector<vector<int>>&adj,string &s,int node,int parent)
{
    if(adj[node].size()==1 &&parent!=-1)
    return 1;
    int best1=0;
    int best2=0;
    for(auto it:adj[node])
    {
        if(it==parent)
        continue;
        
        int candidate=dfs(adj,s,it,node);
        if(s[it]==s[node])
        continue;
        if(candidate>best1)
        {   
            best2=best1;
            best1=candidate;

        }
        else if(candidate>best2)
        best2=candidate;



    }

    ans=max(ans,best1+best2+1);
    return best1+1;

    
}
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<parent.size();i++)
        {
            int u=i;
            int v=parent[i];
            if(v!=-1)
            {
                adj[u].push_back(v);
                 adj[v].push_back(u);
            }
        }

        dfs(adj,s,0,-1);
        return ans;
    }
};