
typedef long long ll;
class Solution {
public:
    vector<int>subtree;
    vector<ll>ans;
    vector<vector<int>>mx,mn;
    
    void dfs(int node,int parent,  vector<vector<int>>&adj, vector<int>& cost)
    {
        subtree[node]=1;
        mx[node]={cost[node]};
        mn[node]={cost[node]};

        for(auto child:adj[node])
        {
            if(child==parent)
            continue;
            dfs(child,node,adj,cost);
            subtree[node]+=subtree[child];

            for(auto it:mx[child])
            {
                mx[node].push_back(it);
            }
              for(auto it:mn[child])
            {
                mn[node].push_back(it);
            }

        }

        sort(mx[node].begin(),mx[node].end(),greater<>());
        sort(mn[node].begin(),mn[node].end());
         if (mx[node].size() > 3) mx[node].resize(3);
          if (mn[node].size() > 3) mn[node].resize(3);
  vector<ll> vals;
        for (auto x : mx[node]) vals.push_back(x);
        for (auto x : mn[node]) vals.push_back(x);
       ll best = LLONG_MIN;

if (mx[node].size() >= 3) {
    best = max(best, 1LL * mx[node][0] * mx[node][1] * mx[node][2]);
}

if (mn[node].size() >= 2 && mx[node].size() >= 1) {
    best = max(best, 1LL * mn[node][0] * mn[node][1] * mx[node][0]);
}

if (subtree[node] < 3) {
    ans[node] = 1;
} else {
    ans[node] = max(0LL, best);
}

    }
  
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {

        int a=edges.size();
        int n=a+1;
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        subtree.assign(n,0);
        ans.assign(n,0);
         mx.assign(n, {});
        mn.assign(n, {});

    dfs(0,-1,adj,cost);
    return ans;


    }
};