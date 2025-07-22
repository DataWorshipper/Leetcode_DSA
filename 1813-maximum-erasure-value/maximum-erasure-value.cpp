class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int r=0;
        int l=0;
        unordered_map<int,int>mpp;
        int sum=0;
        int m_sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            mpp[nums[r]]++;
            while(mpp.size()!=r-l+1)
            {
                mpp[nums[l]]--;
                  sum -= nums[l];
                if(mpp[nums[l]]==0)
                mpp.erase(nums[l]);
                l++;

            }
            if(mpp.size()==r-l+1)
            {
                m_sum=max(m_sum,sum);
            }
            r++;
        }
        return m_sum;
    }
};