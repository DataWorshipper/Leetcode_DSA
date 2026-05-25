class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        INF=float('inf')
        dist=[INF]*(n+1)
        dist[k]=0
        pq=[]
        adj=defaultdict(list)
        for u,v,w in times:
            adj[u].append([v,w])
        
        heapq.heappush(pq,(0,k))
        while len(pq)>0:
            distance,node=pq[0]
            heapq.heappop(pq)
            for child,weight in adj[node]:
                if dist[node]+weight<dist[child]:
                    dist[child]=dist[node]+weight
                    heapq.heappush(pq,(dist[node]+weight,child))
        
        mx=max(dist[1:])
        if mx==INF:
            return -1
        else:
            return mx



        