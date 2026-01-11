class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        int n=nums.size();
       
     
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
          
        }

   int ans=0;
   for(int start=0;start<n;start++)
   {    
        unordered_map<int,int>mpp1,mpp2;
       
        for(int i=start;i<n;i++)
        {   
           
            int sum = prefix[i] - (start==0 ? 0 : prefix[start-1]);

            mpp1[sum]++;
            mpp2[nums[i]]++;
            if(mpp2.find(sum)!=mpp2.end())
            ans++;

           

        }
   }

   return ans;


        
    }
};