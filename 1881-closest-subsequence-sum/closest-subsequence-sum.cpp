typedef long long ll;
class Solution {
    vector<long long>s1,s2;
    void subsetsum(vector<ll>& nums,vector<long long>&subset,int index,ll sum)
    {   if(index==nums.size())
    {
        subset.push_back(sum);
        return;
    }

        subsetsum(nums,subset,index+1,sum);
        subsetsum(nums,subset,index+1,sum+nums[index]);

    }



public:
    int minAbsDifference(vector<int>& nums, int goal) {
            int n=nums.size();
        ll mid=n/2;
        vector<ll>left(nums.begin(),nums.begin()+mid);
        vector<ll>right(nums.begin()+mid,nums.end());

    subsetsum(left,s1,0,0);
    subsetsum(right,s2,0,0);
    ll ans=LLONG_MAX;
   sort(s2.begin(),s2.end());

   for(int i=0;i<s1.size();i++)
   {
    ll val=s1[i];
    auto it=lower_bound(s2.begin(),s2.end(),goal-val);
    if(it!=s2.end())
    {
        ans=min(ans,abs(val+*it-goal));
    }

    if(it!=s2.begin())
    {
        it--;
        ans=min(ans,abs(val+*it-goal));
    }
   }
   return ans;



    }
};