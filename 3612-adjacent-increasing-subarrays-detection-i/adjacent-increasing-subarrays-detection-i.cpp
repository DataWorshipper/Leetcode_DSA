class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 1);

      
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1])
                prefix[i] = prefix[i-1] + 1;
        }

       
        for(int l = 0; l + 2*k - 1 < n; l++){
            int mid = l + k - 1;
            int r = l + 2*k - 1;

        
            if(prefix[mid] < k) continue;

            
            int lenRight = prefix[r] - prefix[mid+1] + 1; 
            if(lenRight >= k) return true;
        }

        return false;
    }
};
