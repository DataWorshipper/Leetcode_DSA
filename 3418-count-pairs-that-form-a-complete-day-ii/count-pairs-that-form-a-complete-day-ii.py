from collections import Counter

class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:

        rem = []

        for h in hours:
            rem.append(h % 24)

        cnt = Counter(rem)

        ans = 0

        for r, freq in cnt.items():

            need = (24 - r) % 24

            if need in cnt:

                if r == need:
                    ans += (freq * (freq - 1))
                else:
                    ans += (freq * cnt[need])

        return ans//2 