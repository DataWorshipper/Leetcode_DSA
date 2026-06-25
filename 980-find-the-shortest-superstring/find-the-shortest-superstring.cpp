typedef long long ll;
class Solution {
public:
ll dp[1<<12][13];
pair<ll,ll> par[1<<12][13];
ll f(ll i, ll j, vector<string>& words, vector<vector<ll>>& cost)
{
    string s1 = words[i];
    string s2 = words[j];

    ll ans = 0;

    for (ll len = 1; len <= min(s1.size(), s2.size()); len++)
    {
        string suf = s1.substr(s1.size() - len);
        string pre = s2.substr(0, len);

        if (suf == pre)
            ans = len;
    }

    return ans;
}

    ll f2(ll mask,ll node,vector<vector<pair<ll,ll>>>&adj,ll n)
    {
        if(mask==(1<<n)-1)
        {
            return 0;
        }
        if(dp[mask][node]!=-1)
        return dp[mask][node];
        ll ans=LLONG_MAX;
        for(auto it:adj[node])
        {   
            ll n1=it.first;
            ll wt=it.second;
            ll bit=(mask>>n1)&1;
            if(bit==0)
            {   
                ll nxt=wt+f2(mask|(1<<n1),n1,adj,n);
                if(nxt<ans)
                {
                ans=nxt;
                 par[mask][node] = {mask | (1<<n1), n1};
                }
            }

        }
        return dp[mask][node]=ans;
    }

    string shortestSuperstring(vector<string>& words) {

            ll n=words.size();
            vector<vector<ll>>cost(n,vector<ll>(n,0));
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        ll c=f(i,j,words,cost);
                        cost[i][j]=words[j].size()-c;
                    }
                }
            }
               vector<vector<pair<ll,ll>>>adj(n);
                for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        adj[i].push_back({j,cost[i][j]});
                        adj[j].push_back({i,cost[j][i]});
                       
                    }
                }
            }
            ll mn = LLONG_MAX;
ll startNode = -1;

for (ll i = 0; i < n; i++)
{
    memset(dp, -1, sizeof(dp));
memset(par,-1,sizeof(par));
    ll curr = words[i].size() + f2((1 << i), i, adj, n);

    if (curr < mn)
    {
        mn = curr;
        startNode = i;
    }
}
memset(dp,-1,sizeof(dp));
memset(par,-1,sizeof(par));
f2((1<<startNode),startNode,adj,n);

ll mask = (1<<startNode);
ll node = startNode;
string order="";
order.append(words[node]);

while(mask != (1<<n)-1)
{
   ll prev = node;

auto p = par[mask][node];

mask = p.first;
node = p.second;

order += words[node].substr(words[node].size() - cost[prev][node]);
}
return order;



            

            


    }
};