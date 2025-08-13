class Solution {
public:
    int minDistance(string word1, string word2) {
       
    int l1=word1.size();
    int l2=word2.size();
   
    vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
    for(int i=0;i<=l1;i++)
    {
        dp[i][0]=i;
        
    }
    for(int i=0;i<=l2;i++)
    {
        dp[0][i]=i;
        
    }
    for(int i=1;i<=l1;i++)
    
{
    for(int j=1;j<=l2;j++)
    {
        if(word1[i-1]==word2[j-1])
        dp[i][j]=dp[i-1][j-1];
        else
        {
            int del=1+dp[i-1][j];
            int ins=1+dp[i][j-1];
            int replace=1+dp[i-1][j-1];
            dp[i][j]=min(del,min(ins,replace));
        }
    }
}
return dp[l1][l2];

    }
};