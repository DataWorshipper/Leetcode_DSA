class Solution {
public:
   int minPatches(vector<int>& nums, int n) {
        int patches=0;
        long long max_reachable_number=0;
    int i=0;
        while(max_reachable_number<n)
        {
            if(i<nums.size()&&nums[i]<=max_reachable_number+1 )
            {
                max_reachable_number+=nums[i];
                i++;
            }
            else 
            {
                
                  max_reachable_number+=(max_reachable_number+1);
                  patches++;
            }

        }
        return patches;
    }
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        return minPatches(coins,target);
    }
};