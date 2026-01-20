typedef long long ll;
class Solution {

public:

    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<ll>prefix(n,0);
        prefix[0]=nums[0];
        for(ll i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }

    ll ans=0;
        for(ll i=0;i<n;i++)
        {
            ll low=i;
            ll high=n-1;
            ll final_index=i-1;
            while(low<=high)
            {
                ll mid=low+(high-low)/2;
                ll sum=prefix[mid]-(i>0?prefix[i-1]:0);
                if(1LL*sum*(mid-i+1)<k)
                {
                    final_index=mid;
                    low=mid+1;
                }
                else
                high=mid-1;
            }   

            ans+=(ll)(final_index-i+1);


        }

        return ans;

    }
};