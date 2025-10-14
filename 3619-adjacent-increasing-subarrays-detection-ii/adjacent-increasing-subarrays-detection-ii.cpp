class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        vector<int>prefix(nums.size(),1);
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                prefix[i]=prefix[i-1]+1;
            }
        }
      
        int l=0;
        int r=0;
        while(r<n)
        {   
            if(r-l+1==2*k)
            {   
                int diff1=0;
                int diff2=0;
                int mid=(l+r)/2;
                if(l==0)
                {
                    diff1=prefix[mid];
                    diff2=prefix[r]-prefix[mid+1]+1;
                }
                else
                {
                    diff1=prefix[mid]-prefix[l]+1;   
                    diff2=prefix[r]-prefix[mid+1]+1;
                }

                if(diff1>=k && diff2>=k)  
                    return true;

                l++;
            }
            r++;
        }

        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n / 2;
        int best = 0;

        while(low <=high){
            int mid = (low + high) / 2;
            if(hasIncreasingSubarrays(nums, mid)){
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best;
    }
};
