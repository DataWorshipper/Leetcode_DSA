class Solution {
public:
bool check(vector<int>& nums, int k,int d)
{
    long long  ops=0;
    for(int i=0;i<nums.size();i++)
    {   
        if(nums[i]<=d)
        continue;
        int x=(nums[i]+d-1)/d;
        ops+=(x-1);

    }
    if(ops<=k)
    return true;
    else
    return false;
}

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high)
        {   int mid=low+(high-low)/2;
            if(check(nums,maxOperations,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};