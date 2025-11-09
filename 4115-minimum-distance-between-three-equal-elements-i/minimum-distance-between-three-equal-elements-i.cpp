class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,set<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].insert(i);
        }

        int ans = INT_MAX;

        for(auto &p : mpp){   
            auto &st = p.second;  

            if(st.size() < 3) continue;

            auto it_l = st.begin();
            auto it_r = next(it_l, 2);

            while(it_r != st.end()){
                int left_val = *it_l;
                int right_val = *it_r;

                ans = min(ans, 2 * (right_val - left_val));

                it_l++;
                it_r++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
