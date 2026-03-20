typedef long long ll;
class Solution {
public:
bool check(int n)
{
    string s = to_string(n);
    int len = s.size();
    if(len == 1) return true;

    bool inc = s[1] > s[0];

    for(int i = 1; i < len; i++)
    {
        if(inc)
        {
            if(s[i] <= s[i-1]) return false;
        }
        else
        {
            if(s[i] >= s[i-1]) return false;
        }
    }
    return true;
}

ll dp[17][2][4][11][300][2];
ll f(ll index,ll tight,ll trend,ll prev,ll sum,ll valid,string &s)
{

    if(index==s.size())
    {   
        if(valid==0)
        return  0;
        if(trend==0||trend==1)
        return 1;
        else if(trend==2)
        {
            if(check(sum))
            return 1;
            else
            return 0;
        }
        else if(trend==3)
        return 1;
        
    }

    if(dp[index][tight][trend][prev+1][sum][valid]!=-1)
    return (dp[index][tight][trend][prev+1][sum][valid]);


ll limit=(tight==1)?s[index]-'0':9;
ll ans=0;
for(ll d=0;d<=limit;d++)
{   
      ll newtight=tight&(d==s[index]-'0');
    if(valid==0 &&d==0)
    {
        ans+=f(index+1,newtight,trend,-1,sum,0,s);
    }
    else if(valid==0 &&d!=0)
    {
        ans+=f(index+1,newtight,3,d,sum+d,1,s);
    }
    else if(valid==1)
    {
        if(trend==3)
        {
            if(d>prev)
            {
                  ans+=f(index+1,newtight,1,d,sum+d,1,s);

            }
            else if(d<prev)
            {
                ans+=f(index+1,newtight,0,d,sum+d,1,s); 
            }
            else
             ans+=f(index+1,newtight,2,d,sum+d,1,s); 
        }

        else if(trend==0)
        {
               
                if(d<prev)
                ans+=f(index+1,newtight,0,d,sum+d,1,s);
                else
                    ans+=f(index+1,newtight,2,d,sum+d,1,s);
                    }
        else if(trend==1)
        {
               
                if(d>prev)
                ans+=f(index+1,newtight,1,d,sum+d,1,s);
                else
                    ans+=f(index+1,newtight,2,d,sum+d,1,s);
    }

        else
        {
                ans+=f(index+1,newtight,2,d,sum+d,1,s); 
        }
    }
}

return dp[index][tight][trend][prev+1][sum][valid]=ans;

}

    long long countFancy(long long l, long long r) {
        string high=to_string(r);
        memset(dp,-1,sizeof(dp));
        ll ahigh=f(0,1,3,-1,0,0,high);
        memset(dp,-1,sizeof(dp));
       
        string low=to_string(l-1);
         ll alow=f(0,1,3,-1,0,0,low);
        return ahigh-alow;
    }
};