typedef long long ll;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

            ll res=0;
        ll count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                {
                    res++;
                }
                else
                {
                    if(res!=0)
                    {count+=(((long long)res*(res+1))/2);
                    res=0;
                    }
                    
                }
            }
            if(res>0)
            count+=((res*(res+1))/2);

            return count;
    }
};