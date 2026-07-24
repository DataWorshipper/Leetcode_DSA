

class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        MOD = 10**9 + 7

        @cache
        def dp(i, j):
           

            if i == goal:
                return 1 if j == n else 0

            ans = 0

        
            if j < n:
                ans += (n - j) * dp(i + 1, j + 1)

           
            if j > k:
                ans += (j - k) * dp(i + 1, j)

            return ans % MOD

        return dp(0, 0)