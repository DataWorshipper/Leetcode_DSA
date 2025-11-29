class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
      
int c=0;
        for(int i=0;i+2<n;i++)
        {
            if(nums[i]==0)
            {
                nums[i]=1;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                c++;
            }
            else 
            continue;
        }
                if(accumulate(nums.begin(),nums.end(),0)==n)
                return c;
                else
                return -1;
    }
};