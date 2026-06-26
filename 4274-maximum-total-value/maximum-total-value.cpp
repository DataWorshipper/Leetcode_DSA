typedef long long ll;
class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        ll lo=1;
        ll hi=1e9;
        ll ans=0;
        const ll MOD=1e9+7;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            ll cnt=0;
            for(ll i=0;i<value.size();i++)
            {
                ll v=value[i];
                ll d=decay[i];
                if(v>=mid)
                {
                ll term=(v-mid)/d+1;
                ll f_term=max(0LL,term);  
                cnt=(cnt+f_term);
                }
            
            }
            if(cnt>=m)
            {
                ans=mid;
                lo=mid+1;
            }
            else
            hi=mid-1;
        }
        ll tot=0;
        ll sum=0;
        for( ll i=0;i<value.size();i++)
        {
           ll v=value[i];
        ll d=decay[i];
        if(v>=ans)
        {
            ll t=((v-ans)/d)+1;
            tot+=t;
           __int128 cur = (__int128)t * (2LL * v - (t - 1) * d);
            cur /= 2;
            sum =(sum+ (long long)cur)%MOD;

        } 
        }
        ll extra=tot-m;
       ll remove = (__int128)extra * ans % MOD;
ll f_ans = (sum - remove + MOD) % MOD;
     
        return f_ans%MOD;
        
    }
};