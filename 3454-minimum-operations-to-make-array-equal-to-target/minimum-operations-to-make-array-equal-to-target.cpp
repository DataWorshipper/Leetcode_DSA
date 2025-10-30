typedef long long ll;
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {

           
            vector<ll>diff(nums.size());
            for(ll i=0;i<nums.size();i++)
            {
                diff[i]=target[i]-nums[i];
            }
           ll ops=abs(diff[0]);
           ll prev=diff[0];
            for(ll i=1;i<diff.size();i++)
            {
                ll curr=diff[i];
                if(prev*curr<=0)
                {
                    ops+=abs(curr);
                }

               else if(abs(curr)>abs(prev))
                {
                    ops+=(abs(curr-prev));
                }
                prev=curr;
            }
            return ops;

    }
};