class Solution {
public:
    int dp[1001][1001];

    int rec(int x,
            int i,
            vector<int>& nums,
            int k,
            map<int, vector<int>>& mpp)
    {
        int &ans = dp[x][i];
        if(ans != -1) return ans;

        ans = 2;

        auto &v = mpp[nums[x] % k];

        auto it = lower_bound(v.begin(), v.end(), i + 1);

        if(it != v.end())
        {
            int y = *it;

            ans = max(ans,
                      1 + rec(i, y, nums, k, mpp));

            ++it;
        }

        return ans;
    }

    int maximumLength(vector<int>& nums, int k) {

        int n = nums.size();

        map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++)
            mpp[nums[i] % k].push_back(i);

        memset(dp, -1, sizeof(dp));

        int ans = 1;

        for(int x = 0; x < n; x++)
        {
            for(int i = x + 1; i < n; i++)
            {
                ans = max(ans,
                          rec(x, i, nums, k, mpp));
            }
        }

        return ans;
    }
};