from typing import List
from heapq import heappush, heappop

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])

        INF = float('inf')
        dist = [[[INF] * 2 for _ in range(m)] for _ in range(n)]

        dist[0][0][0] = 0
        pq = [(0, 0, 0, 0)]

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while pq:
            time, r, c, parity = heappop(pq)

            if time != dist[r][c][parity]:
                continue

            if r == n - 1 and c == m - 1:
                return time

            cost = 1 if parity == 0 else 2
            next_parity = 1 - parity

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if 0 <= nr < n and 0 <= nc < m:
                    new_time = max(time, moveTime[nr][nc]) + cost

                    if new_time < dist[nr][nc][next_parity]:
                        dist[nr][nc][next_parity] = new_time
                        heappush(
                            pq,
                            (new_time, nr, nc, next_parity)
                        )

        return -1