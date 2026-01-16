typedef long long ll;
#define v vector
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

class Solution {
    ll findRange(ll i, const v<v<ll>>& range) {
        ll l = 0, r = (ll)range.size() - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (range[mid][0] <= i && i <= range[mid][1]) return mid;
            else if (i < range[mid][0]) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

public:
    long long appealSum(string s) {
        ll n = s.size();

      
        v<ll> prefix(n,0);
        v<int> seen(26,0);
        ll distinct = 0;
        for(ll i=0;i<n;i++){
            if(!seen[s[i]-'a']){
                seen[s[i]-'a']=1;
                distinct++;
            }
            prefix[i]=distinct;
        }

        
        v<v<ll>> range;
        ll f=0,l=0,x=prefix[0];
        for(ll i=1;i<n;i++){
            if(prefix[i]==x){
                l++;
            }else{
                range.push_back({f,l});
                f=i;
                l=i;
                x=prefix[i];
            }
        }
        range.push_back({f,l});

    
        v<ll> diff(range.size());
        for(ll i=0;i<range.size();i++)
            diff[i]=range[i][1]-range[i][0]+1;

       
        v<ll> prefix2(diff.size());
        prefix2[0]=diff[0];
        for(ll i=1;i<diff.size();i++)
            prefix2[i]=prefix2[i-1]+diff[i];

       
        v<ll> pre(range.size(),0);
        for(ll i=1;i<range.size();i++){
            ll ans=0,freq=i+1;
            for(ll j=0;j<i;j++){
                ans += diff[j]*freq;
                freq--;
            }
            pre[i]=ans;
        }
vector<ll> last(26, -1);
ll curAdd = 0;  

  ll appeal = 0;
ll curRange = 0;
ll start = range[0][0], end = range[0][1];

for(ll i=0;i<n;i++){
  
    int ch = s[i] - 'a';
    if(last[ch] == -1){
        curAdd += (i + 1);
    } else {
        curAdd += (i - last[ch]);
    }
    last[ch] = i;

    ll r = findRange(i,range);
    ll before = appeal;

    ll add = curAdd;  

    appeal += add;}





        return appeal;
    }
};
