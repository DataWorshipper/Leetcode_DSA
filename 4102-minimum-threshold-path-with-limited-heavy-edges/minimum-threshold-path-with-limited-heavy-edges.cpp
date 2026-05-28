typedef long long ll;
class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
       if(source==target)
       return 0;
       
        auto f=[&](vector<vector<pair<ll,ll>>>&adj)
        {
            deque<pair<ll,ll>>dq;
            vector<ll>dist(n,LLONG_MAX);
            dist[source]=0;
            dq.push_back({0,source});
            while(!dq.empty())
            {
                int node=dq.front().second;
                dq.pop_front();
                for(auto it:adj[node])
                {
                    int child=it.first;
                    int w=it.second;
                    if(dist[node]+w<dist[child])
                    {
                        dist[child]=dist[node]+w;
                        if(w==0)
                        dq.push_front({dist[node]+w,child});
                        else
                        dq.push_back({dist[node]+w,child});
                    }
                }                
            }
            if(dist[target]<=k)
            return true;
            else
            return false;};

    ll low=0;
    ll high=1e9;
    ll ans=-1;
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto it:edges)
        {
            ll u=it[0];
            ll v=it[1];
            ll w=it[2];
            ll cost=0;
            if(w>mid)
            cost=1;
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});

        }
        bool check=f(adj);
        if(check)
        {
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return ans;

        
    }
};