from sortedcontainers import SortedList
class Solution:
    def distantSubarrays(self, nums: list[int], goal: int, k: int) -> int:
        n = len(nums)
        if k==0:
            return n*(n+1)//2
        P = [0] * (n + 1)

        for i in range(n):
            P[i + 1] = P[i] + nums[i]

        s = SortedList()
        s.add(P[0])

        ans = 0

        for j in range(n):
            x = P[j + 1]

            ans += s.bisect_right(x - goal - k)
            ans += len(s) - s.bisect_left(x - goal + k)

            s.add(x)

        return ans