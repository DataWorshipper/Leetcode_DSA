class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:

        m = len(grid)
        n = len(grid[0])

        dirn = [(1,0), (-1,0), (0,1), (0,-1)]

        INF = float('inf')

        dist = [[INF] * n for _ in range(m)]

        dq = deque()

        dq.appendleft((0, 0, 0))

        dist[0][0] = 0

        while dq:

            x, y, cost = dq.popleft()

            
            for dx, dy in dirn:

                nx = x + dx
                ny = y + dy

                if 0 <= nx < m and 0 <= ny < n:

                    w = grid[nx][ny]

                    if cost + w < dist[nx][ny]:

                        dist[nx][ny] = cost + w

                        if w == 0:
                            dq.appendleft((nx, ny, cost + w))
                        else:
                            dq.append((nx, ny, cost + w))

        return dist[m-1][n-1]