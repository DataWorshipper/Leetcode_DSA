typedef long long ll;
const ll MOD=1e9+7;
class Solution {
public:
ll dp[23][2][225];
ll f(ll index,ll tight,ll sum,string &s,int min_sum, int max_sum)
{
    if(index==s.size())
    {
        if(sum>=min_sum &&sum<=max_sum)
        {
            return 1;
        }
        else
        return 0;
    }
    if(dp[index][tight][sum]!=-1)
    return dp[index][tight][sum];

    ll limit =9;
    if(tight==1)
    limit=s[index]-'0';
    ll ans=0;
    for(ll i=0;i<=limit;i++)
    {
        ll  newtight=tight&(i==s[index]-'0');
        if(sum<=max_sum)
        {
            ans= (ans+f(index+1,newtight,sum+i,s,min_sum,max_sum))%MOD;
        }

    }

    return dp[index][tight][sum]=ans;
}   
string f1(string num)
{   
    int i=num.size()-1;
    while (i >= 0) {
        if (num[i] > '0') {
            num[i]--; 
            break;
        } else {
            num[i] = '9';
            i--;
        }
    }

    return num;

}
    int count(string num1, string num2, int min_sum, int max_sum) {

        num1=f1(num1);
      memset(dp, -1, sizeof(dp));
ll count2 = f(0,1,0,num2,min_sum,max_sum);

memset(dp, -1, sizeof(dp));
ll count1 = f(0,1,0,num1,min_sum,max_sum);

return (count2 - count1 + MOD) % MOD;


    }
};