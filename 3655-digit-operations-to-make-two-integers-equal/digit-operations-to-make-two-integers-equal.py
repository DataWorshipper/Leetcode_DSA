from heapq import heappush, heappop
from typing import List

class Solution:
    def minOperations(self, n: int, m: int) -> int:
        is_prime = [True] * 10000
        is_prime[0] = is_prime[1] = False

        for i in range(2, 100):
            if is_prime[i]:
                for j in range(i * i, 10000, i):
                    is_prime[j] = False

        if is_prime[n] or is_prime[m]:
            return -1

        dist = [float('inf')] * 10000
        dist[n] = n

        pq = [(n, n)]

        while pq:
            cost, x = heappop(pq)

            if cost != dist[x]:
                continue

            if x == m:
                return cost

            digits = list(map(int, str(x)))

            for i in range(len(digits)):
                for change in (-1, 1):
                    nd = digits[i] + change

                    if nd < 0 or nd > 9:
                        continue

                    if i == 0 and nd == 0:
                        continue

                    old = digits[i]
                    digits[i] = nd

                    y = int(''.join(map(str, digits)))

                    digits[i] = old

                    if is_prime[y]:
                        continue

                    new_cost = cost + y

                    if new_cost < dist[y]:
                        dist[y] = new_cost
                        heappush(pq, (new_cost, y))

        return -1