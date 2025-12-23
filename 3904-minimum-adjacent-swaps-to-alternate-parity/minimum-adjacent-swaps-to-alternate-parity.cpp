class Solution {
    vector<int>diff(vector<int>&nums,vector<int>&arr)
    {
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=arr[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }


    vector<int>makearray(vector<int>&nums,int start)
    {
        vector<int>res(nums.size());
        res[0]=start;
        for(int i=1;i<res.size();i++)
        {
            res[i]=1-res[i-1];
        }
        return res;

    }

int ans(vector<int>& indices, vector<int>& nums) {
    vector<int> evenIdx, oddIdx;

   
    for (int idx : indices) {
        if (nums[idx] == 0) evenIdx.push_back(idx);
        else oddIdx.push_back(idx);
    }

    if (evenIdx.size() != oddIdx.size())
        return INT_MAX;

    int a = 0;
    for (int i = 0; i < evenIdx.size(); i++) {
        a += abs(evenIdx[i] - oddIdx[i]);
    }
    return a;
}


public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]%2;
            mpp[nums[i]%2]++;
                    }
                    if(abs(mpp[1]-mpp[0])>1)
                    return -1;


            
        vector<int>a=makearray(nums,0);
        vector<int>b=makearray(nums,1);
        vector<int>diffa=diff(nums,a);
        vector<int>diffb=diff(nums,b);

            int sum=accumulate(nums.begin(),nums.end(),0);
            if(sum==0 || sum==n)
            return -1;
        if(diffa.size()%2==1 &&diffb.size()%2==1)
        return -1;

    int f_ans=INT_MAX;
            if(diffa.size()%2==0)
            f_ans=min(f_ans,ans(diffa,nums));
            
            if(diffb.size()%2==0)
            f_ans=min(f_ans,ans(diffb,nums));

        return f_ans;



    }
};