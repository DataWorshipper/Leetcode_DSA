
class Solution:
    def minCost(self, m: int, n: int, penalty: List[List[int]]) -> int:
        dist = defaultdict(lambda: float('inf'))
        dist[(0, 0, 1)] = 1

        pq = []
        heapq.heappush(pq, (1, 0, 0, 1))

        while pq:
            time, i, j, parity = heapq.heappop(pq)

            if time > dist[(i, j, parity)]:
                continue
           
            newtime = time + penalty[i][j]
            if newtime < dist[(i, j, 1 - parity)]:
                dist[(i, j, 1 - parity)] = newtime
                heapq.heappush(pq, (newtime, i, j, 1 - parity))

         
            if parity == 0:
                if i - 1 >= 0:
                    newtime = time + i * (j + 1)
                    if newtime < dist[(i - 1, j, 1)]:
                        dist[(i - 1, j, 1)] = newtime
                        heapq.heappush(pq, (newtime, i - 1, j, 1))

                if j - 1 >= 0:
                    newtime = time + (i + 1) * j
                    if newtime < dist[(i, j - 1, 1)]:
                        dist[(i, j - 1, 1)] = newtime
                        heapq.heappush(pq, (newtime, i, j - 1, 1))

                if i + 1 < m:
                    newtime = time + (i + 2) * (j + 1) + penalty[i][j]
                    if newtime < dist[(i + 1, j, 1)]:
                        dist[(i + 1, j, 1)] = newtime
                        heapq.heappush(pq, (newtime, i + 1, j, 1))

                if j + 1 < n:
                    newtime = time + (i + 1) * (j + 2) + penalty[i][j]
                    if newtime < dist[(i, j + 1, 1)]:
                        dist[(i, j + 1, 1)] = newtime
                        heapq.heappush(pq, (newtime, i, j + 1, 1))

         
            else:
                if i + 1 < m:
                    newtime = time + (i + 2) * (j + 1)
                    if newtime < dist[(i + 1, j, 0)]:
                        dist[(i + 1, j, 0)] = newtime
                        heapq.heappush(pq, (newtime, i + 1, j, 0))

                if j + 1 < n:
                    newtime = time + (i + 1) * (j + 2)
                    if newtime < dist[(i, j + 1, 0)]:
                        dist[(i, j + 1, 0)] = newtime
                        heapq.heappush(pq, (newtime, i, j + 1, 0))

                if i - 1 >= 0:
                    newtime = time + i * (j + 1) + penalty[i][j]
                    if newtime < dist[(i - 1, j, 0)]:
                        dist[(i - 1, j, 0)] = newtime
                        heapq.heappush(pq, (newtime, i - 1, j, 0))

                if j - 1 >= 0:
                    newtime = time + (i + 1) * j + penalty[i][j]
                    if newtime < dist[(i, j - 1, 0)]:
                        dist[(i, j - 1, 0)] = newtime
                        heapq.heappush(pq, (newtime, i, j - 1, 0))

        return min(dist[(m-1, n-1, 0)], dist[(m-1, n-1, 1)])