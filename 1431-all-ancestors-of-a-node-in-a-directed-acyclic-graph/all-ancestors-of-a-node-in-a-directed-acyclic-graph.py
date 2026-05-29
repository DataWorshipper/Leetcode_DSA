class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ans = [set() for _ in range(n)]
        adj=defaultdict(list)
        indegree=[0]*n
        for u,v in edges:
            adj[u].append(v)
            indegree[v]+=1
        q=deque()
        for i in range(n):
            if indegree[i]==0:
                q.append(i)

        
        while q:
            node=q.popleft()
            for child in adj[node]:
                for e in ans[node]:
                    ans[child].add(e)
                ans[child].add(node)
                indegree[child]-=1
                if indegree[child]==0:
                    q.append(child)
        res = [[] for _ in range(n)]

        for i in range(n):
            res[i] = list(ans[i])
            res[i].sort()
            

        return res
      
        
        


        