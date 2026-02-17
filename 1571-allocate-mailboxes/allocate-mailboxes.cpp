class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        if(n <= k) return 0;

        sort(houses.begin(), houses.end());

        vector<int> prefix(n);
        prefix[0] = houses[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + houses[i];
        }

       
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {

                int mid = (l + r) / 2;

            
                int leftSum = prefix[mid] - (l > 0 ? prefix[l-1] : 0);
                int leftCost = houses[mid] * (mid - l + 1) - leftSum;

             
                int rightSum = prefix[r] - prefix[mid];
                int rightCost = rightSum - houses[mid] * (r - mid);

                cost[l][r] = leftCost + rightCost;
            }
        }

    
        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX));

       
        for(int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
        }

     
        for(int m = 2; m <= k; m++) {
            for(int i = 0; i < n; i++) {

                for(int j = 0; j < i; j++) {
                    if(dp[j][m-1] == INT_MAX) continue;

                    dp[i][m] = min(dp[i][m],
                                   dp[j][m-1] + cost[j+1][i]);
                }
            }
        }

        return dp[n-1][k];
    }
};
