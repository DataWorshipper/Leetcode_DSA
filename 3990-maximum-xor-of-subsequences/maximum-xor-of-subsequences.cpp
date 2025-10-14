class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        
        vector<int>basis(32,0);
        for(int num:nums)
        {
            for(int i=31;i>=0;i--)
            {   
                 if (!(num & (1 << i))) continue;
                int bit=(num>>i)&1;
                if(basis[i]==0 &&bit==1)
                {
                    basis[i]=num;
                    break;
                }
                
                else if(basis[i]!=0)
                {
                    num^=basis[i];
                }

            }

        }

        int maxor=0;
        for(int i=31;i>=0;i--)
        {
            maxor=max(maxor,maxor^basis[i]);
        }
        return maxor;
    }
};