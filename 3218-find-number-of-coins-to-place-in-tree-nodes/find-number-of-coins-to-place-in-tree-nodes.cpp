#define ll long long
#define v vector
class Solution {
public:
v<ll>ans;
v<priority_queue<ll,v<ll>,greater<ll>>>mx;
v<priority_queue<ll>>mn;
v<ll>subtree;
void dfs(ll node,ll parent,v<v<ll>>&adj, vector<int>&cost)
{   
    subtree[node]=1;
    mn[node].push(cost[node]);
    mx[node].push(cost[node]);
    for(auto it:adj[node])
    {
        if(it==parent)
        continue;
        dfs(it,node,adj,cost);
        subtree[node]+=subtree[it];

        if(mx[node].size()<mx[it].size())
        {
            swap(mx[node],mx[it]);
        }
        while(mx[it].size()>0)
        {
            ll val=mx[it].top();
          
            mx[node].push(val);
            if(mx[node].size()>3)
            mx[node].pop();

            mx[it].pop();
        }
        if(mn[node].size()<mn[it].size())
        {
            swap(mn[node],mn[it]);
        }
        while(mn[it].size()>0)
        {
            ll val=mn[it].top();
          
            mn[node].push(val);
            if(mn[node].size()>3)
            mn[node].pop();

              mn[it].pop();
        }

    }

    if(subtree[node]<3)
    {
        ans[node]=1;
    }else
    {
    v<ll>a;
    v<ll>b;
    auto tempMn = mn[node];
auto tempMx = mx[node];
    while(tempMn.size()>0)
    {
        a.push_back(tempMn.top());
        tempMn.pop();
    }   

     while(tempMx.size()>0)
    {
        b.push_back(tempMx.top());
        tempMx.pop();
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll max_cost=LLONG_MIN;
    if(b.size()==3)
    {
        max_cost=max(max_cost,b[0]*b[1]*b[2]);
    }
    if(a.size()>=2 and b.size()>0)
    {
        max_cost=max(max_cost,a[0]*a[1]*b.back());
    }
    if(max_cost<0)
    ans[node]=0;
    else
    ans[node]=max_cost;

    }

}
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
       
        ll n=edges.size()+1;
        v<v<ll>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        ans.resize(n,0);
        subtree.resize(n,0);
        mn.resize(n);
        mx.resize(n);
        dfs(0,-1,adj,cost);
        return ans;

        
    }
};