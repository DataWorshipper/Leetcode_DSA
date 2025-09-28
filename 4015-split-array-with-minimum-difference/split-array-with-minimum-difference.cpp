class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];
        long long total = prefix[n-1];

        vector<bool> inc(n, true);
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]) inc[i] = false;
            else inc[i] = inc[i-1];
        }

        vector<bool> dec(n, true);
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= nums[i+1]) dec[i] = false;
            else dec[i] = dec[i+1];
        }

        long long ans = LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1]){
                long long left_sum = prefix[i];
                long long right_sum = total - left_sum;
                ans = min(ans, abs(left_sum - right_sum));
            }
        }

        if(ans == LLONG_MAX) return -1;
        return ans;
    }
};
