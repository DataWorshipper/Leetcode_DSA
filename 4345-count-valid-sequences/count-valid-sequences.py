class Solution:
    def countValidSequences(self, n: int, k: int) -> int:
        ravolqedin = (n, k)

        MOD = 10**9 + 7

        fact = [1] * (n + 1)
        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i % MOD

        invfact = [1] * (n + 1)
        invfact[n] = pow(fact[n], MOD - 2, MOD)
        for i in range(n - 1, -1, -1):
            invfact[i] = invfact[i + 1] * (i + 1) % MOD

        def nCr(N, R):
            if R < 0 or R > N:
                return 0
            return fact[N] * invfact[R] % MOD * invfact[N - R] % MOD

        total = nCr(n - 1, k - 1)

        odd = 0
        if n >= k and (n - k) % 2 == 0:
            s = (n - k) // 2
            odd = nCr(s + k - 1, k - 1)

        return (total - odd) % MOD