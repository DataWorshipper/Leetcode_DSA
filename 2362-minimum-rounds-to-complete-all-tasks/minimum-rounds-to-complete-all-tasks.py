class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        freq = Counter(tasks)
        ans = 0

        for f in freq.values():
            if f == 1:
                return -1

            if f % 3 == 0:
                ans += f // 3
            else:
                ans += f // 3 + 1

        return ans
        