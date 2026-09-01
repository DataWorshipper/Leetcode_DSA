from collections import deque

class Solution:
    def minOperations(self, nums: list[int], sum: int) -> int:
        INF = 10**9
        n = len(nums)

        reachable = {}

        for x in set(nums):
            reachable[x] = []
            vis = set()
            q = deque([(x, 0, 0)])
            vis.add((x, 0))

            while q:
                val, mode, ops = q.popleft()

                if val <= sum:
                    reachable[x].append((val, ops))

                if mode == 0:
                    nv = val * 2
                    if nv <= 5000 and (nv, 0) not in vis:
                        vis.add((nv, 0))
                        q.append((nv, 0, ops + 1))

                nv = val // 2
                if nv > 0 and (nv, 1) not in vis:
                    vis.add((nv, 1))
                    q.append((nv, 1, ops + 1))

        dp = [[INF] * (sum + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            x = nums[i - 1]

            for s in range(sum + 1):
                dp[i][s] = dp[i - 1][s]

                for val, ops in reachable[x]:
                    if val <= s:
                        dp[i][s] = min(
                            dp[i][s],
                            dp[i - 1][s - val] + ops
                        )

        return -1 if dp[n][sum] == INF else dp[n][sum]