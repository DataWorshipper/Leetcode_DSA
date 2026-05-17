typedef long long ll;
#define  v vector
class Solution {
public:
    string longestDupSubstring(string s) {
        const ll MOD1=1e9+7;
        const ll MOD2=1e9+9;
        ll n=s.size();
        const ll p = 911382323LL;
        v<ll>pref1(n+1,0);
        v<ll>pref2(n+1,0);
        v<ll>power1(n+1,1);
        v<ll>power2(n+1,1);
        for(ll i=0;i<n;i++)
        {   
            int val=s[i]-'a'+1;
            pref1[i+1]=(pref1[i]*p+val)%MOD1;
             pref2[i+1]=(pref2[i]*p+val)%MOD2;
             power1[i+1]=(power1[i]*p)%MOD1;
             power2[i+1]=(power2[i]*p)%MOD2;
        }

        ll low=1;
        ll ans=0;
        ll high=n-1;
        map<int,int>mpp2;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            ll l=0;
            ll r=0;
            map<pair<ll,ll>,ll>mpp;
            bool flag=false;
            while(r<n)
            {
                while(r-l+1==mid)
                {
                    ll hash1=(pref1[r+1]-(pref1[l]*power1[r-l+1])%MOD1+MOD1)%MOD1;
                     ll hash2=(pref2[r+1]-(pref2[l]*power2[r-l+1])%MOD2+MOD2)%MOD2;
                     mpp[make_pair(hash1,hash2)]++;
                     if( mpp[make_pair(hash1,hash2)]==2)
                     {
                        flag=true;
                        mpp2[mid]=l;
                        break;
                     }
                     l++;
                    
                }
                if(flag==true)
                break;
                r++;
            }
            if(flag)
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;

        }

        return s.substr(mpp2[ans],ans);






    }
};