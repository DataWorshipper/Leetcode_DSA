class Solution {
public:
    bool ispossible(vector<int>& nums,int maxsum,int p)

{
    int c=0;
    for(int i=0;i<nums.size()-1;i++)
    {
        int f=nums[i];
        int s=nums[i+1];
        if(abs(f-s)<=maxsum)
        {
            c++;
            i++;
            
        }
    }
    return c>=p;
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int  high=nums[nums.size()-1]-nums[0];
int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(nums,mid,p)==true)
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