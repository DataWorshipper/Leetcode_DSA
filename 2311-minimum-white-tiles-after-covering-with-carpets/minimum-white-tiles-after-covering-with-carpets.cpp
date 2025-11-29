class Solution {
public:
int dp[1002][1002];
int f(int index,int carpets,int len,string &floor)
{
    int n=floor.size();
    if(index>=n)
    {
        return 0;
    }

    if(carpets<0)
    {
        return INT_MAX/4;
    }
    if(dp[index][carpets]!=-1)
    return dp[index][carpets];

   
   int nocover=INT_MAX;
   if(floor[index]=='1')
   {
    nocover=1+f(index+1,carpets,len,floor);
   }
   else
   nocover=f(index+1,carpets,len,floor);

   int cover=INT_MAX;

   if( carpets>=1)
   cover=f(index+len,carpets-1,len,floor);

   return dp[index][carpets]=min(cover,nocover);



}
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp,-1,sizeof(dp));
    return f(0,numCarpets,carpetLen,floor);
   
    }
};