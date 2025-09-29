#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {

    // Recursive DP: returns max profit starting from index
    ll f(vector<tuple<int,int,int>>& jobs, vector<ll>& dp, int index) {
        if(index >= jobs.size()) return 0;      // base case
        if(dp[index] != -1) return dp[index];  // memoization

        // Option 1: skip current job
        ll not_take = f(jobs, dp, index + 1);

        // Option 2: take current job
        int current_end = get<1>(jobs[index]);
        int next_index = jobs.size();
        int low = index + 1, high = jobs.size() - 1;

        // Binary search for next non-overlapping job
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(get<0>(jobs[mid]) >= current_end) {
                next_index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ll take = get<2>(jobs[index]) + f(jobs, dp, next_index);

        return dp[index] = max(take, not_take);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int,int,int>> jobs(n);

        // Create tuples of (start, end, profit)
        for(int i = 0; i < n; i++) {
            jobs[i] = make_tuple(startTime[i], endTime[i], profit[i]);
        }

        // Sort by start time
        sort(jobs.begin(), jobs.end());

        vector<ll> dp(n, -1);
        return f(jobs, dp, 0);
    }
};
