class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        n = len(s)

        suffix = [0] * n
        suffix[n - 1] = n - 1

        for i in range(n - 2, -1, -1):
            if s[i] > s[suffix[i + 1]]:
                suffix[i] = i
            else:
                suffix[i] = suffix[i + 1]

        for i in range(n):
            if s[suffix[i]] > s[i]:
                s[i], s[suffix[i]] = s[suffix[i]], s[i]
                break

        return int(''.join(s))