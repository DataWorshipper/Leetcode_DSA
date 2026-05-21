from collections import deque

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        n = len(grid)

        q = deque()
        vis = [[0] * n for _ in range(n)]

        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j, 0))
                    vis[i][j] = 1

        
        if len(q) == 0 or len(q) == n * n:
            return -1

        dirs = [(1,0), (-1,0), (0,1), (0,-1)]

        ans = 0

        while q:

            x, y, dist = q.popleft()

            ans = max(ans, dist)

            for dx, dy in dirs:

                nx = x + dx
                ny = y + dy

                if 0 <= nx < n and 0 <= ny < n:

                    if vis[nx][ny] == 0 and grid[nx][ny] == 0:

                        vis[nx][ny] = 1
                        q.append((nx, ny, dist + 1))

        return ans