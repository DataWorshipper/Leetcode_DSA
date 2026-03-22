class Solution {
public:
    int rev(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<int> d(n);
        
       
        for (int i = 0; i < n; i++) {
            d[i] = nums[i] - rev(nums[i]);
        }
        
        unordered_map<int, long long> mpp;
        
    
        for (int x : d) {
            mpp[x]++;
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
           
            mpp[d[i]]--;
            if (mpp[d[i]] == 0) {
                mpp.erase(d[i]);
            }
            
          
            if (mpp.count(d[i])) {
                ans = (ans + mpp[d[i]]) % MOD;
            }
        }
        
        return ans;
    }
};