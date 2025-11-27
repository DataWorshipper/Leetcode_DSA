typedef long long ll;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        vector<ll>prefix(nums.size()+1,0);
        
        for(ll i=1;i<=nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }

    int n=nums.size();
    unordered_map<ll,set<ll>>mpp;
    for(ll i=0;i<=n;i++)
    {
        ll rem=i%k;
        mpp[rem].insert(i);
    }
    ll ans=LLONG_MIN;
    for(auto it:mpp)
    {
        ll r=it.first;
        set<ll>st=it.second;
        ll min_pref=LLONG_MAX;
        ll max_pref=LLONG_MIN;
        for(auto it:st)
        {
            if(min_pref!=LLONG_MAX)
            max_pref=max(max_pref,prefix[it]-min_pref);

             min_pref=min(min_pref,prefix[it]);
        }
    ans=max(ans,max_pref);

    }

     return (ans==LLONG_MIN)?0:ans;

    }
};