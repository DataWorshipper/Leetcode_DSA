class Solution {
public:
    long long minOperations(vector<int>& nums) {
       
        long long  ans=0;
        for(int i=1;i<nums.size();i++)
        {
         int val=nums[i]-nums[i-1];
         if(val<0)
         {
ans+=abs(val);
         }   
        }
        return ans;


        
    }
};