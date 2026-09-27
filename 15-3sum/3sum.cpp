class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        for (int k = 0; k < n; k++) {
            int i = 0;
            int j = n - 1;

            while (i < j) {
                if (i == k) {
                    i++;
                    continue;
                }

                if (j == k) {
                    j--;
                    continue;
                }

                int s = nums[i] + nums[j];
                int val = -nums[k];

                if (s > val) {
                    j--;
                }
                else if (s < val) {
                    i++;
                }
                else {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);

                    i++;
                    j--;
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};