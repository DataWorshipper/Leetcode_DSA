class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        B = 60
        cnt = [0] * B

        
        for x in nums:
            for b in range(B):
                if (x >> b) & 1:
                    cnt[b] += 1

        ans = 0

        for x in nums:

            for b in range(B):
                if (x >> b) & 1:
                    cnt[b] -= 1

            y = x << k

        
            for b in range(B):
                if (y >> b) & 1:
                    cnt[b] += 1

            cur = 0
            for b in range(B):
                if cnt[b] > 0:
                    cur |= (1 << b)

            ans = max(ans, cur)

            for b in range(B):
                if (y >> b) & 1:
                    cnt[b] -= 1

            for b in range(B):
                if (x >> b) & 1:
                    cnt[b] += 1

        return ans