class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        import heapq

        arr = []
        k = len(queries)
        for i in range(k):
            arr.append((queries[i], i))
        arr.sort()

        m = len(grid)
        n = len(grid[0])

        pq = []
        heapq.heappush(pq, (grid[0][0], 0, 0))

        vis = [[0] * n for _ in range(m)]
        vis[0][0] = 1

        ans = [0] * k
        points = 0

        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]

        for curr_q, curr_idx in arr:

            while pq and pq[0][0] < curr_q:

                val, i, j = heapq.heappop(pq)
                points += 1

                for s in range(4):
                    new_x = i + dx[s]
                    new_y = j + dy[s]

                    if (0 <= new_x < m and
                        0 <= new_y < n and
                        not vis[new_x][new_y]):

                        vis[new_x][new_y] = 1
                        heapq.heappush(
                            pq,
                            (grid[new_x][new_y], new_x, new_y)
                        )

            ans[curr_idx] = points

        return ans