class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int can=nums[0];
        int n=nums.size();
        for(int i=1;i<nums.size();i++)
        {
            can&=nums[i];
        }
    if(can!=0)
    return 1;
        int ans=0;
        int curr=(1<<21)-1;
        for(int i=0;i<n;i++)
        {
            curr=curr&nums[i];
            if(curr==can)
            {
                ans++;
                curr=(1<<21)-1;
            }
        }
        return ans;
    }
};