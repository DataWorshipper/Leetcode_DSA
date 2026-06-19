

class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        MOD = 10**9 + 7

        cnt = defaultdict(int)
        s = defaultdict(int)
        n = len(nums)

        for i in range(n):
            x = nums[i]

            cnt[x] = (cnt[x] + 1 + cnt[x - 1] + cnt[x + 1]) % MOD

            s[x] = (
                s[x]
                + x
                + cnt[x - 1] *x+ s[x - 1]
                + cnt[x + 1] *x+ s[x + 1]
            ) % MOD

        return sum(s.values()) % MOD

      