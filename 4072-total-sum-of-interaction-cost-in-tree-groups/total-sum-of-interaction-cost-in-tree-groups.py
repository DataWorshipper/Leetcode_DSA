class Solution:
    def interactionCosts(self, n: int, edges: List[List[int]], group: List[int]) -> int:
        adj=defaultdict(list)
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)

        total=defaultdict(int)
        for g in group:
            total[g]+=1
        cnt=[defaultdict(int) for _ in range(n)]
        def dfs(node,parent):
            cnt[node][group[node]]=1
            for it in adj[node]:
                if parent==it:
                    continue
                dfs(it,node)
                for g in cnt[it]:
                    cnt[node][g]+=cnt[it][g]
        dfs(0,-1)
        ans=0
        def dfs2(node,parent):
            nonlocal ans
            
            for it in adj[node]:
                if it==parent:
                    continue
                mpp=defaultdict(int)
                for g in total:
                    mpp[g]=total[g]-cnt[it][g]
                for g in mpp:
                    ans+=(mpp[g]*cnt[it][g])
                dfs2(it,node)
        dfs2(0,-1)
        return ans
