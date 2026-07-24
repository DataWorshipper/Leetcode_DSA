from functools import cache

class Solution:
    def sumOfPower(self, nums, k):
        MOD = 10**9 + 7
        n = len(nums)

        @cache
        def dp(i, s):
            if i == n:
                return 1 if s == k else 0
            
            if s > k:
                return 0

            ans = 0

           
            ans += dp(i + 1, s)

       
            ans += dp(i + 1, s)
           
            ans += dp(i + 1,s+nums[i])

            return ans % MOD

        return (
            dp(0, 0)
          
        ) % MOD