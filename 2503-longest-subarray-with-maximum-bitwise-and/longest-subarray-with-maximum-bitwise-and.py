class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums)

        ans = cur = 0
        for x in nums:
            if x == mx:
                cur += 1
                ans = max(ans, cur)
            else:
                cur = 0

        return ans