typedef long long ll;
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_map<ll,ll>mpp;
        ll n=nums.size();
        for(auto it:nums)
        {
            mpp[it]++;
        }
        unordered_map<ll,ll>mpp2;
        set<ll>s1(nums.begin(),nums.end());
        ll mx=*max_element(nums.begin(),nums.end());
        for(auto it:s1)
        {
            mpp2[it]=it;
        }
        for(auto it:s1)
        {
            ll val=it;
            for(ll j=2*val;j<=mx;j+=val)
            {
                if(mpp.find(j)!=mpp.end())
                {
                    mpp2[j]=min(mpp2[j],val);
                }
            }
        }
ll s=0;
        for(ll i=0;i<n;i++)
        {
            s+=mpp2[nums[i]];
        }
        return s;

    }
};