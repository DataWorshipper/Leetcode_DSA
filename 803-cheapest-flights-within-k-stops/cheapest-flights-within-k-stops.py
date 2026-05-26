class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        mn = float('inf')

        adj = defaultdict(list)

        for u, v, w in flights:
            adj[u].append([v, w])

        

        dist = [float('inf')] * n
        q=deque()
        q.append((0,src,0))

        dist[src] = 0

        while q:
            stops,node,d = q.popleft()

            if stops >k+1:
                continue

            if node == dst:
                mn = min(mn, d)
                

            for child, weight in adj[node]:

                
                   if d+weight<dist[child]:
                        dist[child]=d+weight
                        q.append(
                            
                            (stops+1,child,d+weight)
                        )

        if mn == float('inf'):
            return -1
        else:
            return mn