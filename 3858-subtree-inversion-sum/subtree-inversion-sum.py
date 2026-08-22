class Solution:
    def subtreeInversionSum(self, edges: List[List[int]], nums: List[int], k: int) -> int:
        adj=defaultdict(list)
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        n=len(nums)
        dp=[[[-float("inf")]*(k+1) for _ in range(2)] for _ in range(n)]

        INF=float("inf")

        def dfs(node,parity,d_last,parent):
            ans=-INF

            if dp[node][parity][d_last]!=-INF:
                return dp[node][parity][d_last]

            for ch in adj[node]:
                if ch==parent:
                    continue
                else:
                    if d_last<k:
                        dfs(ch,parity,min(k,d_last+1),node)
                    else:
                        dfs(ch,parity,min(k,d_last+1),node)
                        dfs(ch,parity^1,1,node)

            s1=nums[node] if parity==0 else -nums[node]
            
            for ch in adj[node]:
                if ch==parent:
                    continue
                s1+=dp[ch][parity][min(k,d_last+1)]

            ans=max(ans,s1)

            if d_last>=k:
                s2=-nums[node] if parity==0 else nums[node]
                for ch in adj[node]:
                    if ch==parent:
                        continue
                    s2+=dp[ch][parity^1][1]

                ans=max(ans,s2)

            dp[node][parity][d_last]=ans
            return ans
        
        return dfs(0,0,k,-1)