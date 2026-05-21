class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj=defaultdict(list)
        for u,v in connections:
            adj[u].append((v,1))
            adj[v].append((u,0))
        sum=0
        vis=[0]*n
        def dfs(node,adj):
            nonlocal sum
            vis[node]=1
            
            for child,weight in adj[node]:
                if vis[child]==0:
                    sum+=weight
                    dfs(child,adj)
            
        dfs(0,adj)
        return sum


        

        