class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
       
     
        ans=float('inf')
        for i in range(n):

                vis = [0] * n   
                q=deque()
                dist = [-1] * n
                q.append((i,-1))
                vis[i]=1
                dist[i]=0
                while q:
                    node,parent=q.popleft()
                    for child in adj[node]:
                        if vis[child]==1 and child!=parent:
                            ans=min(ans,dist[node]+dist[child]+1)
                        if vis[child]==0:
                            vis[child]=1
                            q.append((child,node))
                            dist[child]=dist[node]+1
        if ans==float('inf'):
            return -1
        else:
            return ans


