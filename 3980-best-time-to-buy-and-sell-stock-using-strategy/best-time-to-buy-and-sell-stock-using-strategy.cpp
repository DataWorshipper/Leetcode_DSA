typedef long long ll;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

    ll n=prices.size();
        vector<ll>a;
        vector<ll>prefix(n,0);
        for(ll i=0;i<prices.size();i++)
            {
                a.push_back((1LL*prices[i]*strategy[i]));
            }
        prefix[0]=a[0];
        for(ll i=1;i<a.size();i++)
            {
                prefix[i]=prefix[i-1]+a[i];
            }

        vector<ll>pre(n,0);
        pre[0]=prices[0];
        for(ll i=1;i<n;i++)
            {
                pre[i]=pre[i-1]+prices[i];
            }
        ll net=LLONG_MIN;
        ll sum=accumulate(a.begin(),a.end(),0LL);
ll l=0;
        ll r=0;
        while(r<n)
            {

                while(r-l+1>k)
                    {
                        l++;
                    }

                    if(r-l+1==k)
                        {
                            ll b;
                        if(l==0)
                        {
                            b=prefix[r];
                        }
                            else
                            b=prefix[r]-prefix[l-1];

                            ll c=pre[r]-pre[l+k/2-1];

                            net=max(net,c-b);
                            
                    }
                r++;
            }

        if(net<=0)
            return sum;
        else
            return sum+net;
            
        

        
    }
};