class Solution:
    def findMedian(self, n: int, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        LOG = 20

        up = [[-1] * LOG for _ in range(n)]
        wup = [[0] * LOG for _ in range(n)]
        depth = [0] * n
        wdepth=[0]*n
        adj = defaultdict(list)

        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))


        def dfs(node, parent, wt, d,wd):
            depth[node] = d
            wdepth[node]=wd
            up[node][0] = parent
            wup[node][0] = wt

            for j in range(1, LOG):
                p = up[node][j - 1]

                if p != -1:
                    up[node][j] = up[p][j - 1]
                    wup[node][j] = wup[node][j - 1] + wup[p][j - 1]

            for nxt, edge_wt in adj[node]:
                if nxt != parent:
                    dfs(nxt, node, edge_wt, d + 1,wd+edge_wt)


        dfs(0, -1, 0, 0,0)
        def node_lift(a,dist):
            for i in range(LOG):
                bit=(dist>>i)&1
                if bit==1:
                    a=up[a][i]
            return a


        def lca(a,b):
            if depth[b]>depth[a]:
                a,b=b,a
            dis=depth[a]-depth[b]
            a=node_lift(a,dis)
            if a==b:
                return b
            
            for i in range(LOG-1, -1, -1):
                anA=up[a][i]
                anB=up[b][i]
                if  anA != -1 and anA != anB:
                    a=anA
                    b=anB
            
            return up[a][0]

        def wdis(u,v):
            LCA=lca(u,v)
            return wdepth[u]+wdepth[v]-2*wdepth[LCA]
        ans=[]
        for u, v in queries:
            L = lca(u, v)

            ulca = wdepth[u] - wdepth[L]
            vlca = wdepth[v] - wdepth[L]

            distance = ulca + vlca
            need = (distance + 1) // 2
            if need==ulca:
                ans.append(L)
            elif need <=ulca:
                rem = need
                curr=u
                for i in range(LOG - 1, -1, -1):
                    if up[curr][i] != -1 and wup[curr][i] < rem:
                        rem -= wup[curr][i]
                        curr = up[curr][i]
                        
                if rem==0:
                    ans.append(curr)
                else:
                    ans.append(up[curr][0])

            else:
                spill = need - ulca
                allowed = vlca - spill

                cur = v
                rem = allowed

                for i in range(LOG - 1, -1, -1):
                    if up[cur][i] != -1 and wup[cur][i] <=rem:
                        rem -= wup[cur][i]
                        cur = up[cur][i]
                
                ans.append(cur)
        return ans

                




                
            

            



                







        