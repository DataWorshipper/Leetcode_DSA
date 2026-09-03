from sortedcontainers import SortedSet
class Solution:
    def kthSmallest(self, par: List[int], vals: List[int], queries: List[List[int]]) -> List[int]:
        mpp=defaultdict(list)
        adj = defaultdict(list)
        ans=[-1]*len(queries)
        n=len(par)
        for i in range(1, n):
            
            adj[par[i]].append(i)
            adj[i].append(par[i])
        for i in range(len(queries)):
            node=queries[i][0]
            k=queries[i][1]
            mpp[node].append((k,i))
        px = [0] * n

        def dfs1(node, par):
            for child in adj[node]:
                if child == par:
                    continue
                px[child] = px[node] ^ vals[child]
                dfs1(child, node)

        px[0] = vals[0]
        dfs1(0, -1)
        def dfs(node,par):
            st=SortedSet()
            st.add(px[node])
            for child in adj[node]:
                if child==par:
                    continue
                st_child=dfs(child,node)
                if len(st)<len(st_child):
                    st,st_child=st_child,st
                for el in st_child:
                    st.add(el)
            if node not in mpp:
                return st
            
            for k,idx in mpp[node]:
                if len(st)<k:
                    ans[idx]=-1
                else:
                    ans[idx]=st[k-1]
            return st
        
        dfs(0,-1)
        return ans
                




        