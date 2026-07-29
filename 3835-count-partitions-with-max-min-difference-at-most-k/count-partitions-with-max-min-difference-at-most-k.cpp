class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        const int MOD=1e9+7;
        vector<int>pref(n+1,0);
        dp[0]=1;
        pref[0]=dp[0];
        multiset<int>ms;
        ms.insert(nums[0]);
        int l=0;
        for(int r=0;r<n;r++)
        {
            if(r!=0)
            {
                ms.insert(nums[r]);
            }
            while(*ms.rbegin()-*ms.begin()>k)
            {
               ms.erase(ms.find(nums[l]));
                l++;

            }
            dp[r+1]=pref[r];
            if(l!=0)
            {
                dp[r+1]=(dp[r+1]-pref[l-1]+MOD)%MOD;
            }
            pref[r+1]=(pref[r]+dp[r+1])%MOD;
        }
        return dp[n]%MOD;

    }
};