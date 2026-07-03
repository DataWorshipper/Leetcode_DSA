from collections import deque
from typing import List

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

       
        safety = [[float('inf')] * n for _ in range(n)]
        q = deque()

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    safety[i][j] = 0
                    q.append((i, j))

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while q:
            r, c = q.popleft()

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < n and 0 <= nc < n:
                    if safety[nr][nc] == float('inf'):
                        safety[nr][nc] = safety[r][c] + 1
                        q.append((nr, nc))

        def can(threshold):
            if safety[0][0] < threshold:
                return False

            q = deque([(0, 0)])
            vis = [[False] * n for _ in range(n)]
            vis[0][0] = True

            while q:
                r, c = q.popleft()

                if r == n - 1 and c == n - 1:
                    return True

                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc

                    if (
                        0 <= nr < n
                        and 0 <= nc < n
                        and not vis[nr][nc]
                        and safety[nr][nc] >= threshold
                    ):
                        vis[nr][nc] = True
                        q.append((nr, nc))

            return False

        low = 0
        high = max(max(row) for row in safety)
        ans = 0

        while low <= high:
            mid = (low + high) // 2

            if can(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans