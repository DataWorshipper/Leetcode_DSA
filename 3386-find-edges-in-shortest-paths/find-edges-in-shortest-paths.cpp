class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
     
        using pll=pair<int,int>;
           vector<vector<pll>>parent(n);
        vector<vector<pll>>adj(n);
        map<vector<int>,int>mpp;
        for (int i = 0; i < edges.size(); i++)
{
    int a = edges[i][0];
    int b = edges[i][1];
    int w = edges[i][2];

    adj[a].push_back({b, w});
    adj[b].push_back({a, w});

    mpp[{a, b, w}] = i;
    mpp[{b, a, w}] = i; 
}
vector<int>dist(n,INT_MAX);
dist[0]=0;
priority_queue<pll,vector<pll>,greater<pll>>pq;
pq.push({0,0});
while(pq.size()!=0)
{
    auto it = pq.top();
pq.pop();

int d = it.first;
int node = it.second;
    for(auto it:adj[node])
    {
        int nei=it.first;
        int wt=it.second;
        if(dist[node]+wt<dist[nei])
        {   
            dist[nei]=dist[node]+wt;
            pq.push({dist[node]+wt,nei});
            parent[nei].clear();
            parent[nei].push_back({node,wt});
        }
        if(dist[node]+wt==dist[nei])
        {
            parent[nei].push_back({node,wt});
        }
    }
}
if(dist[n-1]==INT_MAX)
{
    vector<bool>ans;
    for(int i=0;i<edges.size();i++)
    {
        ans.push_back(false);
    }
    return ans;
}

       vector<bool> ans(edges.size(), false);
vector<bool> vis(n, false);

queue<int> q;
q.push(n - 1);
vis[n - 1] = true;

while (!q.empty())
{
    int curr = q.front();
    q.pop();

    for (auto &p : parent[curr])
    {
        int par = p.first;
        int w = p.second;

        int index = mpp[{curr, par, w}];
        ans[index] = true;

        if (!vis[par])
        {
            vis[par] = true;
            q.push(par);
        }
    }
}   
return ans;

    }
};