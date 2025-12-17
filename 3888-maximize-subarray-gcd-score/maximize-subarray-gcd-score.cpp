typedef long long ll;
class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
int n=nums.size();
         ll m=LLONG_MIN;   
        for(ll i=0;i<n;i++)
        {   
            ll g=0;
            ll minpower=LLONG_MAX;
            ll mincount=0;
            for(ll j=i;j<n;j++)
            {
                g=gcd(g,nums[j]);

                int v2 = __builtin_ctz(nums[j]);
                if(v2<minpower)
                {
                    minpower=v2;
                    mincount=1;
                }
                else if(v2==minpower)
                {
                    mincount++;
                }
               
                int l=j-i+1;
                if(k>=mincount)
                {
                 
                    m=max(m,l*(2*g));
                }
                else
                m=max(m,l*g);


            }
        }

        return m;
    }
};