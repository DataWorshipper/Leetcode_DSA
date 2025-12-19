typedef long long ll;
class Solution {
    vector<ll>subtree;
    vector<ll>res;
    public:
    void dfs(int node,int parent,  vector<vector<int>>&adj)
    {
        subtree[node]=1;
        for(auto it:adj[node])
        {
            if(it==parent)
            continue;

            dfs(it,node,adj);
            subtree[node]+=subtree[it];
        }
    }
    
    public:
   void result(int node, int parent, vector<vector<int>>& adj, int n)
{
    ll p = 1;

    
    for (auto it : adj[node]) {
        if (it == parent) continue;
        p *= subtree[it];
    }

 
    ll rest = n - subtree[node];
    if (rest > 0) {
        p *= rest;
    }

    res[node] = p;

    for (auto it : adj[node]) {
        if (it == parent) continue;
        result(it, node, adj, n);
    }
}


public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            int u=i;
            int p=parents[i];
            if(p!=-1)
            {
                adj[u].push_back(p);
                adj[p].push_back(u);
            }
        }
        subtree.assign(n,0);
        dfs(0,-1,adj);
        res.assign(n,0);
        result(0,-1,adj,n);

        ll m=*max_element(res.begin(),res.end());

        int c=0;
        for(auto it:res)
        {
            if(it==m)
            c++;
        }

        return c;


    }
};