typedef long long ll;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

            ll low=0;
            ll high=2e14;
            ll ans=0;
            while(low<=high)
            {
                ll mid=low+(high-low)/2;
                __int128 sum=0;
                for(ll i=0;i<batteries.size();i++)
                {
                    if(batteries[i]<mid)
                    sum+=batteries[i];
                    else
                    sum+=mid;
                }
                if(sum>=( (__int128)n * mid ))
                {   
                    ans=mid;
                    low=mid+1;
                }
                else
                high=mid-1;
            }

            return ans;
    }
};