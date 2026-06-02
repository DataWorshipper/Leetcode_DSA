class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> closest(n);

        closest[0] = 1;
        closest[n - 1] = n - 2;

        for (int i = 1; i < n - 1; i++) {
            int left = nums[i] - nums[i - 1];
        int  right = nums[i + 1] - nums[i];

            if (left <= right)
                closest[i] = i - 1;
            else
                closest[i] = i + 1;
        }

        vector<int > prefR(n, 0), prefL(n, 0);

       
        for (int i = 0; i < n - 1; i++) {
            int  cost =
                (closest[i] == i + 1)
                    ? 1
                    : nums[i + 1] - nums[i];

            prefR[i + 1] = prefR[i] + cost;
        }

        for (int i = n - 1; i > 0; i--) {
            int cost =
                (closest[i] == i - 1)
                    ? 1
                    :nums[i] - nums[i - 1];

            prefL[i - 1] = prefL[i] + cost;
        }

        vector<int > ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r)
                ans.push_back(prefR[r] - prefR[l]);
            else
                ans.push_back(prefL[r] - prefL[l]);
        }

        return ans;
    
    }
};