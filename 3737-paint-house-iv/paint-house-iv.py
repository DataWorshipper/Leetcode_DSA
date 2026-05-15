from typing import List
from collections import defaultdict

class Solution:
    def minCost(self, n: int, cost: List[List[int]]) -> int:
        
        dp = defaultdict(lambda: float('inf'))

       
        dp[(0,0,1)] = cost[0][0] + cost[n-1][1]
        dp[(0,0,2)] = cost[0][0] + cost[n-1][2]
        dp[(0,1,0)] = cost[0][1] + cost[n-1][0]
        dp[(0,2,0)] = cost[0][2] + cost[n-1][0]
        dp[(0,2,1)] = cost[0][2] + cost[n-1][1]
        dp[(0,1,2)] = cost[0][1] + cost[n-1][2]

        
        for i in range(1, n // 2):

            dp[(i,0,1)] = min(
                dp[(i-1,1,2)],
                dp[(i-1,1,0)],
                dp[(i-1,2,0)]
            ) + cost[i][0] + cost[n-1-i][1]

            dp[(i,0,2)] = min(
                dp[(i-1,1,0)],
                dp[(i-1,2,1)],
                dp[(i-1,2,0)]
            ) + cost[i][0] + cost[n-1-i][2]

            dp[(i,1,0)] = min(
                dp[(i-1,2,1)],
                dp[(i-1,0,1)],
                dp[(i-1,0,2)]
            ) + cost[i][1] + cost[n-1-i][0]

            dp[(i,2,0)] = min(
                dp[(i-1,0,1)],
                dp[(i-1,1,2)],
                dp[(i-1,0,2)]
            ) + cost[i][2] + cost[n-1-i][0]

            dp[(i,2,1)] = min(
                dp[(i-1,0,2)],
                dp[(i-1,1,2)],
                dp[(i-1,1,0)]
            ) + cost[i][2] + cost[n-1-i][1]

            dp[(i,1,2)] = min(
                dp[(i-1,2,0)],
                dp[(i-1,2,1)],
                dp[(i-1,0,1)]
            ) + cost[i][1] + cost[n-1-i][2]

        ans = float('inf')

        for c1 in range(3):
            for c2 in range(3):
                if c1 != c2:
                    ans = min(ans, dp[(n//2 - 1, c1, c2)])

        return ans