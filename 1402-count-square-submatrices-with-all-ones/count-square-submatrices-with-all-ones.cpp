class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,1));
for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                dp[i][j]=0;
            }
        }

        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {   
                if(matrix[i][j]==1)
                dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1; 
            }
        }
        int s=0;
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {

                s+=dp[i][j];
            }
        }
        return s;

    }
};