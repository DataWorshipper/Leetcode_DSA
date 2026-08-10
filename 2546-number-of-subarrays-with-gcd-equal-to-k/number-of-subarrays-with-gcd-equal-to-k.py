class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        ans=0
        for l in range(len(nums)):
            g = 0

            for r in range(l, len(nums)):
                g = gcd(g, nums[r])

                if g == k:
                    ans += 1
        return ans
                