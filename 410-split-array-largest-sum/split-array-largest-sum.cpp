class Solution {
public:

bool ispossible(vector<int>& nums,int maxsum,int k)
{
    int c=0;
    int sum=0;
    for(auto num:nums)
    {
        
        if(sum+num<=maxsum)
        {
            sum+=num;
        }
        else
        {
            c++;
            sum=num;
        }
    }
    return c<=k-1;
}

    int splitArray(vector<int>& nums, int k) {

    
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(nums,mid,k)==true)
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