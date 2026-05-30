class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n=len(edges)
        adj=defaultdict(list)
        indegree=[0]*n
        vis=[0]*n
        topo=[]
        for i,u in enumerate(edges):
            if u!=-1:
                adj[i].append(u)
                indegree[u]+=1
        
        q=deque()
        for i in range(n):
            if indegree[i]==0:
                q.append(i)
        
        while q:
            node=q.popleft()
            topo.append(node)
            for child in adj[node]:
                indegree[child]-=1
                if indegree[child]==0:
                    q.append(child)
        
        for u in topo:
            vis[u]=1
        def bfs(node,adj,vis):
            cnt=0
            q=deque()
            q.append(node)
            vis[node]=1
            while q:
                node=q.popleft()
                cnt+=1
                for child in adj[node]:
                    if vis[child]==0:
                        
                        vis[child]=1
                        q.append(child)
            
            return cnt
        ans=-1
        for i in range(n):
            if vis[i]:
                continue
            ans=max(ans,bfs(i,adj,vis))
        return ans
            


        

        