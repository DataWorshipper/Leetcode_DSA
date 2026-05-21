from collections import defaultdict
import heapq

class Solution:
    def minScore(self, n, roads):

        adj = defaultdict(list)

        for u, v, w in roads:
            adj[u].append((v, w))
            adj[v].append((u, w))

        dist = [float('inf')] * (n + 1)

        pq = []

        dist[1] = float('inf')

        heapq.heappush(pq, (dist[1], 1))

        while pq:

            curr_score, node = heapq.heappop(pq)

            for nei, w in adj[node]:

                new_score = min(curr_score, w)

                if new_score < dist[nei]:

                    dist[nei] = new_score

                    heapq.heappush(pq, (new_score, nei))

        return dist[n]