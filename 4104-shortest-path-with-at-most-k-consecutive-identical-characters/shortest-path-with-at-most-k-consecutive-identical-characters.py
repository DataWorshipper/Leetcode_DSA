class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        pq=[]
        adj=defaultdict(list)
        for u,v,w in edges:
            adj[u].append((v,w))
           
        INF=float('inf')
        dist=[[INF]*52 for _ in range(n)]
        dist[0][1]=0
        heapq.heappush(pq,((0,0,1)))
        while pq:
            d,node,consec=heapq.heappop(pq)
            if consec>k:
                continue
            for nei,wt in adj[node]:
                new_consec=0
                if  labels[nei]==labels[node]:
                    new_consec=consec+1
                else:
                    new_consec=1
                if new_consec>k:
                    continue
                if dist[node][consec]+wt<dist[nei][new_consec]:
                    dist[nei][new_consec]=dist[node][consec]+wt
                    heapq.heappush(pq,(dist[nei][new_consec],nei,new_consec))
    
        mn=INF
        for val in dist[n-1]:
            mn=min(mn,val)
        if mn==INF:
            return -1
        else:
            return mn



        