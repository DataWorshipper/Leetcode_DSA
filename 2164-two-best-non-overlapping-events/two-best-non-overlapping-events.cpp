typedef long long ll;
class Solution {
public:
    int n;

    ll dfs(vector<vector<int>>& events, int index, int count, vector<vector<ll>>& dp) {
        if(index == n || count == 2) return 0; 

        if(dp[index][count] != -1) return dp[index][count];

     
        ll skip = dfs(events, index + 1, count, dp);

      
        int low = index + 1, high = n - 1, next = n;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(events[mid][0] > events[index][1]) { 
                next = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        ll take = events[index][2] + dfs(events, next, count + 1, dp);

        return dp[index][count] = max(skip, take);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();

     
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

       
        vector<vector<ll>> dp(n, vector<ll>(3, -1));

       
        return dfs(events, 0, 0, dp);
    }
};
