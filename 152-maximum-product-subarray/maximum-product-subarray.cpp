class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n);
        vector<int>dp2(n);
        dp1[0]=nums[0];
        dp2[0]=nums[0];
        for(int i=1;i<n;i++)
        {   
            dp2[i]=min({dp2[i-1]*nums[i],nums[i],dp1[i-1]*nums[i]});
            dp1[i]=max({dp1[i-1]*nums[i],nums[i],dp2[i-1]*nums[i]});

        }

        return *max_element(dp1.begin(),dp1.end());
    }
};