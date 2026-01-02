
class Solution {
    int dp[10][2][2][1<<10];
    public:
int f(int index,int tight,int valid,int mask,string &s)
{
    if(index==s.size())
    {
        if(valid)
        return 1;
        else
        return 0;
    }

    if(dp[index][tight][valid][mask]!=-1)
    return dp[index][tight][valid][mask];

    int limit=(tight==1)?s[index]-'0':9;
    int ans=0;
    for(int i=0;i<=limit;i++)
    {
        int newtight=tight&(i==s[index]-'0');

       if(valid==0&&i==0)
       {    
        ans+=f(index+1,newtight,0,mask,s);
       }
       else if(valid==0 &&i>0)
       {
        ans+=f(index+1,newtight,1,mask^(1<<i),s);
       }
       else 
       {
        if(!(mask&(1<<i)))
        {
            ans+=f(index+1,newtight,1,mask^(1<<i),s);
        }
       }

    
    }
       return dp[index][tight][valid][mask]=ans;
}
public:
    int numDupDigitsAtMostN(int n) {
         string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return n-f(0,1,0,0,s);
    }
};