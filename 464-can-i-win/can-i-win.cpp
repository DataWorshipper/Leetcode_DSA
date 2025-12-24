class Solution {
    bool dp[1<<21][2];
   bool vis[1<<21][2];
    bool f(int mask,int player,int max_n,int tot,int sum)
    {   
        if(sum>=tot)
        return false;

         if (vis[mask][player])
            return dp[mask][player];

        vis[mask][player] = true;
    bool ans=false;
        for(int i=0;i<max_n;i++)
        {
            if(mask&(1<<i))
            {
                if(!f(mask^(1<<i),1-player,max_n,tot,sum+i+1))
                {ans=true;
                break;
                }
                
                
            }
        }

        return dp[mask][player]=ans;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
          if (desiredTotal <= 0) return true;
        if (maxChoosableInteger >= desiredTotal) return true;
         int totalSum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (totalSum < desiredTotal) return false;

           memset(vis, false, sizeof(vis));
             memset(dp, false, sizeof(dp));
        return f((1 << maxChoosableInteger) - 1, 0,maxChoosableInteger,desiredTotal,0);
            
    }
};