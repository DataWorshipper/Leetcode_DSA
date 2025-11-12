class Solution {
public:
    int minOperations(vector<int>& nums) {
        int g=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            g=gcd(g,nums[i]);
            if(nums[i]==1)
            c++;
        }

        if(g>1)
        return -1;
        else if(c>0)
        return nums.size()-c;

        int best=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                curr=gcd(curr,nums[j]);
                if(curr==1)
                {
                    best=min(best,j-i+1);
                    break;
                }
            }
        }

        return nums.size()+best-2;
      

        
    }
};