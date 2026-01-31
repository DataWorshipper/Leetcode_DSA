typedef long long ll;
class Solution {
public:
    bool check(vector<int>& nums,ll k)
        {
            ll ops=0;
        for(auto it:nums)
            {
                ops+=(it+k-1)/k;
            }
            return ops<=(k*k);
    }
    int minimumK(vector<int>& nums) {

        ll low=1;
   ll a=*max_element(nums.begin(),nums.end());
        ll b=(ll)ceil(sqrt((long double)nums.size()));
        ll high=1e9;
        ll ans=-1;
        while(low<=high)
            {
                ll mid=(low+high)/2;
                if(check(nums,mid))
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }

        return (int)ans;
    }
};