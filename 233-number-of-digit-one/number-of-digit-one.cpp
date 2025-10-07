typedef long long ll;
class Solution {
public:
ll dp[11][2][11];
ll f(ll index,ll tight,ll cnt,string &s)

{
    if(index==s.size())
    {
        return cnt;

    }

    if(dp[index][tight][cnt]!=-1)
    return dp[index][tight][cnt];

    ll limit=9;
    if(tight==1)
    limit=s[index]-'0';
    ll ans=0;
    for(ll i=0;i<=limit;i++)
    {
        ll newtight=(tight)&(i==s[index]-'0');
        if(i==1)
        {
            ans+=f(index+1,newtight,cnt+1,s);
        }
        else
        ans+=f(index+1,newtight,cnt,s);
    }
    return dp[index][tight][cnt] = ans;

}

    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return f(0,1,0,s);
    }
};