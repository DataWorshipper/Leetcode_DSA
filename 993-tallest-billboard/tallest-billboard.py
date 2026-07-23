class Solution:
    def tallestBillboard(self, rods):
        n = len(rods)
        memo = {}
        INF = float('-inf')

        def dp(idx, diff):
            if idx == n:
                if diff == 0:
                    return 0
                return INF

            if (idx, diff) in memo:
                return memo[(idx, diff)]

            x = rods[idx]

            
            skip = dp(idx + 1, diff)

        
            taller = dp(idx + 1, diff + x)

            
            shorter = dp(idx + 1, abs(diff - x)) + min(diff, x)

            memo[(idx, diff)] = max(skip, taller, shorter)
            return memo[(idx, diff)]

        return dp(0, 0)