typedef long long ll;
class Solution {
public:
const ll MOD=1e9+7;
vector<ll>fact;
vector<ll>invfact;
ll binexp(ll base, ll exp) {
        ll res = 1;
        while(exp > 0) {
            if(exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }
 void factorial()
 {
    fact[0]=1;
    fact[1]=1;
    for(ll i=2;i<fact.size();i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
 }

void inverse()
{
    int n = invfact.size() - 1;
invfact[n] = binexp(fact[n], MOD-2);
    for(int i=invfact.size()-2;i>=0;i--)
    {
        invfact[i]=(invfact[i+1]*(i+1))%MOD;
    }
}

ll f(string s)
{
    unordered_map<char,int>mpp;
    for(char c:s)
    {
        mpp[c]++;
    }
    ll ans1=1;
    for(auto it:mpp)
    {
        if(it.second>1)
        {
            ans1=(ans1*invfact[it.second])%MOD;
        }
    }

    return (fact[s.size()]*ans1)%MOD;
}
    int countAnagrams(string s) {
        
        fact.resize(1e5+1);
        invfact.resize(1e5+1);
        factorial();
        inverse();

        stringstream ss(s);
        string word;
        ll ans=1;
        while(ss>>word)
        {
            ans=(ans*f(word))%MOD;
        }

        return ans;

    }
};