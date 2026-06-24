class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        q=deque()
        seen=set()
        n=len(graph)
        mask=0
        for i in range(n):
            q.append((i,mask|(1<<i),0))
            seen.add((i,mask|(1<<i)))
        
        while q:
            node,mask,cost=q.popleft()
            if mask==(1<<n)-1:
                return cost
            for neigh in graph[node]:
                new_mask=mask|(1<<neigh)
                if (neigh,new_mask) not in seen:
                    q.append((neigh,new_mask,cost+1))
                    seen.add((neigh,new_mask))
        
        return -1
            

