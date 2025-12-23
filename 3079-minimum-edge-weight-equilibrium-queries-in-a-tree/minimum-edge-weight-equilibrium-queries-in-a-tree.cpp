typedef long long ll;
class Solution {
    int up[10001][20];
    int depth[10001];
    int cnt[10001][27];
    public:
    void lifting(int node,int parent, vector<vector<pair<int,int>>>& adj)
    {
        up[node][0]=parent;
        for(int i=1;i<20;i++)
        {   if(up[node][i-1]!=-1)
            up[node][i]=up[up[node][i-1]][i-1];
        }
        for(auto it:adj[node])
        {
            if(it.first==parent)
            continue;
            else
            lifting(it.first,node,adj);
        }
    }  
    
    void d(int node,int parent,int d1,vector<vector<pair<int,int>>>& adj)
    {   
        depth[node]=d1;
        for(auto it:adj[node])
        {
            if(it.first==parent)
            continue;
            d(it.first,node,d1+1,adj);
        }
    } 
    int  node_lift(int node,int dis)
    {
        for(int i=0;i<20;i++)
        {
           
            if (dis & (1 << i)) {
    node = up[node][i];
}

          
        }

        return node;
    }
    int lca(int u,int v)
    {
        if(depth[u]>depth[v])
        swap(u,v);
        int distance=depth[v]-depth[u];
        v= node_lift( v, distance);
        if(u==v)
        return u;
        for(int i=19;i>=0;i--)
        {
            if(up[u][i]!=up[v][i])
            {
                u=up[u][i];
                v=up[v][i];
            }
        }
        return up[u][0];
    }

   void dfs(int u, int p, vector<vector<pair<int,int>>>& adj) {
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;

      
       for (int i = 0; i < 27; i++) {
    cnt[v][i] = cnt[u][i];
}
cnt[v][w]++;


     
    

        dfs(v, u, adj);
    }
}

int query(int a, int b) {
    int l = lca(a, b);
    int dist = depth[a] + depth[b] - 2 * depth[l];

    int mx = 0;
    for (int w = 0; w < 27; w++) {
        int freq = cnt[a][w] + cnt[b][w] - 2 * cnt[l][w];
        mx = max(mx, freq);
    }

    return dist - mx;
}



   
public:

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {     
        int s=edges.size();
        vector<vector<pair<int,int>>>adj(s+1);
        memset(up, -1, sizeof(up));

        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
              adj[v].push_back({u,w});
        }

        lifting(0,-1,adj);
        d(0,-1,0,adj);
        dfs(0,-1,adj);

        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            ans[i]=query(a,b);
        }
        return ans;
    }


};