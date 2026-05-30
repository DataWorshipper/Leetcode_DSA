class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj=defaultdict(list)
        n=len(colors)
        indegree=[0]*n
        for u,v in edges:
            adj[u].append(v)
            indegree[v]+=1
        
        dp=[[0]*26 for _ in range(n)]
        for i in range(n):
            ch=colors[i]
            id=ord(ch)-ord('a')
            dp[i][id]=1
        
        q=deque()
        for i in range(n):
            if indegree[i]==0:
                q.append(i)
        cnt=0
        while q:
            node=q.popleft()
            cnt+=1
            for child in adj[node]:
                for i in range(26):
                    val=dp[node][i]
                    if i==ord(colors[child])-ord('a'):
                        val+=1
                    dp[child][i]=max(dp[child][i],val)
                indegree[child]-=1
                if indegree[child]==0:
                    q.append(child)
        ans=float('-inf')
        for i in range(n):
            for j in range(26):
                ans=max(ans,dp[i][j])
        if cnt!=n:
            return -1
        return ans


        