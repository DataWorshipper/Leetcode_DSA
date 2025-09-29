class Solution {
public:
    int f(vector<vector<int>>& events, int k, vector<vector<int>>& dp, int index, int count) {
        if(index > events.size()-1 || count >=k) return 0;
        if(dp[index][count] != -1) return dp[index][count];

        int not_take = f(events, k, dp, index + 1, count);

      
        int low = index + 1, high = events.size() - 1, next = events.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(events[mid][0] > events[index][1]) {
                next = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int take = events[index][2] + f(events, k, dp, next, count + 1);

        return dp[index][count] = max(take, not_take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
     
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return f(events, k, dp, 0, 0);
    }
};
