class Solution {
    vector<unordered_map<int,int>>cnt;
    unordered_map<int,int>total;
    long long ans=0;
    void dfs(int node,int parent,  vector<vector<int>>&adj,vector<int>&group)
    {
        cnt[node][group[node]]=1;
        for(auto it:adj[node])
            {
            if(it==parent)
                continue;

            dfs(it,node,adj,group);
        for(auto &[g,L]:cnt[it])
            {
                long long R=total[g]-L;
                ans+=(L*R);
                
            }
                

                for(auto &[g,c]:cnt[it])
                    cnt[node][g]+=c;
        
            }
    }
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {

        vector<vector<int>>adj(n);
        for(auto it:edges)

            {
                int u=it[0];
                int v=it[1];
                adj[u].push_back(v);
                 adj[v].push_back(u);
            }

        for(int g:group)

            {
                total[g]++;
            }
        cnt.resize(n);
        dfs(0,-1,adj,group);
        return ans;
    }
};