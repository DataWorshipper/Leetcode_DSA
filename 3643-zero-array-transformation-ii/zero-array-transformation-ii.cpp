class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        bool f=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                f=false;
                break;
            }
        }
        if(f)
        return 0;
        int low=0;
        int high =queries.size()-1;
        int ans=-1;
        while(low<=high)

        {
            int mid=low+(high-low)/2;

            vector<long long>diff(nums.size(),0);
            for(int i=0;i<=mid;i++)
            {
                int l=queries[i][0];
                int r=queries[i][1];
                int val=queries[i][2];
                diff[l]+=val;
                if(r+1<nums.size())
                diff[r+1]-=val;
            }
            for(int i=1;i<diff.size();i++)
            {
                diff[i]+=diff[i-1];
            }

            bool flag=true;
            for(int i=0;i<diff.size();i++)
            {
                if(diff[i]<nums[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {   ans=mid+1;
                high=mid-1;
            }
            else
            low=mid+1;

        }

        return ans;
    }
};