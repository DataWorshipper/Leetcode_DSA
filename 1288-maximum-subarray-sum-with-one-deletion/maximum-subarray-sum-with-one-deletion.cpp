class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        
        dp[0][0]=arr[0];
        dp[0][1]=INT_MIN/2;
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0]+arr[i],arr[i]);
            dp[i][1]=max(dp[i-1][1]+arr[i],dp[i-1][0]);
        }

        int m=INT_MIN;
        for(int i=0;i<n;i++)
        {
            m=max(m,*max_element(dp[i].begin(),dp[i].end()));
        }
        return m;

    }
};