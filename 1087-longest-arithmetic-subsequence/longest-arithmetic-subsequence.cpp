class Solution {
public:
    int dp[1001][1001];

    int rec(int i, int x, vector<int>& nums,
            map<int, vector<int>>& mpp)
    {
        if(dp[i][x] != -1)
            return dp[i][x];

        int ans = 2;   

        int d = nums[i] - nums[x];
        int target = nums[x] - d;

        if(mpp.count(target)) {
            auto &v = mpp[target];

            auto it = lower_bound(v.begin(), v.end(), x);

            if(it != v.begin()) {
                it--;
                int y = *it;

                ans = max(ans, 1 + rec(x, y, nums, mpp));
            }
        }

        return dp[i][x] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++)
            mpp[nums[i]].push_back(i);

        memset(dp, -1, sizeof(dp));

        int ans = 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                ans = max(ans, rec(i, j, nums, mpp));
            }
        }

        return ans;
    }
};
