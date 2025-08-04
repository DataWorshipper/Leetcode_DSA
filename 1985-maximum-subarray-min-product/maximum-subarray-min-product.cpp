class Solution {
public:
    vector<int> nse(vector<int>& nums) {
        vector<int> nse(nums.size(), nums.size());
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> pse(vector<int>& nums) {
        vector<int> pse(nums.size(), -1);
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> right = nse(nums);
        vector<int> left = pse(nums);

        long long res = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i] + 1;
            int r = right[i] - 1;
            long long total = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
            res = max(res, total * nums[i]);
        }
        return res % 1000000007;
    }
};
