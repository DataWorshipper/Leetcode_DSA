class Solution {
public:
int offset=1000;
int ways(int index,int sum,vector<vector<int>>&dp,int target,vector<int>& nums)
{
    if(index==nums.size())
    {
        if(sum==target)
        return 1;
        else return 0;
    }

    if(dp[index][sum+offset]!=-1)
    return dp[index][sum+offset];
    int a=ways(index+1,sum+nums[index],dp,target,nums);
    int b=ways(index+1,sum-nums[index],dp,target,nums);
    return dp[index][sum+offset]=a+b;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2002,-1));
return  ways(0,0,dp,target,nums);
    }
};