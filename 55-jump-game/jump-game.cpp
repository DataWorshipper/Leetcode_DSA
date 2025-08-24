class Solution {
public:
    bool canJump(vector<int>& nums) {
        int c=0;
        for(auto it:nums)
        {
            if(it==0)
            c++;
        }
        if(c==0)
        return true;
        int farthest=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(farthest>n-1)
            return true;
            if(i>farthest)
            return false;

            farthest=max(farthest,i+nums[i]);

        }

        return true;
    }
};