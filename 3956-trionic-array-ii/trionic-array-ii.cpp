typedef long long ll;
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>dp1(n,LLONG_MIN);
        vector<ll>dp2(n,LLONG_MIN);
        vector<ll>dp3(n,LLONG_MIN);
        
        for(ll i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {   

                dp1[i]=nums[i]+nums[i-1];
                if(dp1[i-1]!=LLONG_MIN)
                dp1[i]=max(dp1[i],dp1[i-1]+nums[i]);
            }
        }
    
         for(ll i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {  if (dp2[i-1] != LLONG_MIN)
    dp2[i] = max(dp2[i], dp2[i-1] + nums[i]);

if (dp1[i-1] != LLONG_MIN)
    dp2[i] = max(dp2[i], dp1[i-1] + nums[i]);
            }
        }
      

for(ll i = 1; i < n; i++)
{
    if(nums[i] > nums[i-1])
    {
        if(dp2[i-1] != LLONG_MIN)
            dp3[i] = max(dp3[i], dp2[i-1] + nums[i]);

        if(dp3[i-1] != LLONG_MIN)
            dp3[i] = max(dp3[i], dp3[i-1] + nums[i]);
    }
}
        ll ans=*max_element(dp3.begin(),dp3.end());
        return ans;


    }
};