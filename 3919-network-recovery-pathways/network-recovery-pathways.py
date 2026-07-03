class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        adj=defaultdict(list)
        n=len(online)
        indegree=[0]*n
        INF=float('inf')
        min_w=INF
        max_w=-INF
        for u,v,w in edges:
            adj[u].append((v,w))
            min_w=min(min_w,w)
            max_w=max(max_w,w)
            indegree[v]+=1
        
        def topo(wt,deg):
          
            dist=[INF]*n
            dist[0]=0
            q=deque()
            for i,val in enumerate(deg):
                if val==0:
                    q.append(i)
        
            while q:
                node=q.popleft()
                for u,w in adj[node]:
                    if dist[node]!=INF and (online[u]==True or u==n-1) and w>=wt:
                       dist[u]=min(dist[u],w+dist[node])
                    deg[u]-=1
                    if deg[u]==0:
                        q.append(u)
            
            if dist[n-1]==INF or dist[n-1]>k:
                return False
            else:
                return True
        
        low=min_w
        high=max_w
        ans=-1
        
        while low<=high:
            mid=low+(high-low)//2
            deg=indegree[:]
            flag=topo(mid,deg)
            if flag==True:
                ans=mid
                low=mid+1
            else:
                high=mid-1
        return ans



                
                        







            
        