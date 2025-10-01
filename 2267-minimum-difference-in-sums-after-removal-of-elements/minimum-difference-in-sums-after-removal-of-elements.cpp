typedef long long ll;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        ll n=nums.size();
        ll k=n/3;
        vector<ll>prefix(n,0);
         vector<ll>suffix(n,0);
       
         priority_queue<ll>max_heap;
          priority_queue<ll,vector<ll>,greater<ll>>min_heap;
         ll curr_sum=0;
         for(ll i=0;i<=(n-k-1);i++)
         {
            curr_sum+=nums[i];
            max_heap.push(nums[i]);
            while(max_heap.size()>k)
            { curr_sum-=max_heap.top();
                max_heap.pop();
               
            }
            prefix[i]=curr_sum;


         }

 
curr_sum = 0;

         for(ll i=n-1;i>=k;i--)
         {

            curr_sum+=nums[i];
            min_heap.push(nums[i]);
            while(min_heap.size()>k)
            { curr_sum-=min_heap.top();
                min_heap.pop();
               

            }
            suffix[i]=curr_sum;
         }

    ll diff=LLONG_MAX;
         for(ll i=k-1;i<(n-k);i++)
         {
            ll wtf=prefix[i]-suffix[i+1];
            diff=min(diff,wtf);
         }
         return diff;



    }
};