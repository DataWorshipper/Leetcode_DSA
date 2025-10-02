class Solution {
public:
    long long dfs(vector<vector<int>>& offers, int index, vector<long long>& dp) {
        if(index == offers.size()) return 0;
        if(dp[index] != -1) return dp[index];
        long long skip = dfs(offers, index + 1, dp);
        int low = index + 1, high = offers.size() - 1, next = offers.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(offers[mid][0] > offers[index][1]){
                next = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        long long take = offers[index][2] + dfs(offers, next, dp);
        return dp[index] = max(skip, take);
    }
    
    long long maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<long long> dp(offers.size(), -1);
        return dfs(offers, 0, dp);
    }
};
