class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)

        vis = [0] * n
        colour = [-1] * n
        flag=True
        def dfs(node,c):
            nonlocal flag
            colour[node]=c
            vis[node]=1
            for child in graph[node]:
                if  vis[child] and colour[child]==c:
                    flag=False
                    return
                if vis[child]==0:
                    dfs(child,1-c)
        
        for i in range(n):
            if vis[i]:
                continue
            dfs(i,0)
        
        return flag
        
                

        