class Solution {
public:
int dp[16][1<<16];
int f(int n,int index,int mask)
{
        if(index>n)
        return 1;
        if(dp[index][mask]!=-1)
        return dp[index][mask];

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                if((i+1)%index==0 ||index%(i+1)==0)
                {
                    ans+=f(n,index+1,mask^(1<<i));
                }
            }
        }

        return dp[index][mask]=ans;
}
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
       return f(n,1,(1<<16)-1);
    }
};