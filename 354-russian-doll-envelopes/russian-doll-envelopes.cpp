class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (int i = 0; i < nums.size(); i++) {
            if (LIS.empty() || LIS.back() < nums[i]) {
                LIS.push_back(nums[i]);
            } else {
                auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
                *it = nums[i];
            }
        }

        return LIS.size();
    }
    int maxEnvelopes(vector<vector<int>>& v) {
        
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] >b[1];
    return a[0] < b[0];
});

    vector<int>a;
    for(auto it:v)

    {
        a.push_back(it[1]);
    }

return lengthOfLIS(a);

    }
};