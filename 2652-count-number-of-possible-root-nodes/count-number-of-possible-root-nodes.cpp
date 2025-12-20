class Solution {
    vector<int>par;
    vector<int>res;
    public:
    void dfs(int node,int parent,vector<vector<int>>&adj)
    {
        par[node]=parent;
        for(auto it:adj[node])
        {
            if(it==parent)
            continue;

            dfs(it,node,adj);
        }
    }

    void result(int node,int parent,vector<vector<int>>&adj, set<pair<int,int>>&S)
    {       
        
        for(auto it:adj[node])
        {
            if(it==parent)
            continue;

            res[it]=res[node];
            if(S.count({it,node}))
            {
                res[it]++;
            }
            if(S.count({node,it}))
            {
                res[it]--;
            }
           
            result(it,node,adj,S);


        }
    }

public:

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {

          
            int n=edges.size()+1;
            vector<vector<int>>adj(n);
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

                par.assign(n,0);
                dfs(0,-1,adj);
                res.assign(n,0);
                int correct=0;
                for(auto it:guesses)
                {
                    int u=it[0];
                    int v=it[1];
                    if(par[v]==u)
                    correct++;
                }
                res[0]=correct;
                set<pair<int,int>> S;
    for (auto &g : guesses) {
    S.insert({g[0], g[1]});
}       
result(0,-1,adj,S);
int c=0;
for(auto it:res)
{
    if(it>=k)
    {
        c++;
    }
}
return c;



    }
};