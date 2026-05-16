class Solution:
    def stringCount(self, n: int) -> int:

        MOD = 10**9 + 7

        dp = {}

        def f(index, freq_l, freq_e, freq_t):

            if index == n:
                if freq_l == 1 and freq_e == 2 and freq_t == 1:
                    return 1
                return 0

            if (index, freq_l, freq_e, freq_t) in dp:
                return dp[(index, freq_l, freq_e, freq_t)]

            ans = 0

           
            ans += f(
                index + 1,
                min(1, freq_l + 1),
                freq_e,
                freq_t
            )

            ans += f(
                index + 1,
                freq_l,
                min(2, freq_e + 1),
                freq_t
            )

            ans += f(
                index + 1,
                freq_l,
                freq_e,
                min(1, freq_t + 1)
            )

            
            ans += 23 * f(
                index + 1,
                freq_l,
                freq_e,
                freq_t
            )

            ans %= MOD

            dp[(index, freq_l, freq_e, freq_t)] = ans

            return ans

        return f(0, 0, 0, 0)