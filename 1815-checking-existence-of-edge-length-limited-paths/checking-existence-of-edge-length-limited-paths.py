class Solution:
    def distanceLimitedPathsExist(self, n: int, edges: List[List[int]], queries: List[List[int]]) -> List[bool]:
        
        class DSU():
            def __init__(self,n):
                self.parent=list(range(n+1))
                self.rank=[0]*(n+1)
                self.n=n
            def find_parent(self,u):
                if u==self.parent[u]:
                    return u
                self.parent[u]=self.find_parent(self.parent[u])
                return self.parent[u]
            
            def unite(self,u,v):
                pu=self.find_parent(u)
                pv=self.find_parent(v)
                ru=self.rank[pu]
                rv=self.rank[pv]
                if pu==pv:
                    return
                else:
                    if ru>rv:
                        self.parent[pv]=pu
                    elif ru<rv:
                        self.parent[pu]=pv
                    else:
                        self.parent[pu]=pv
                        self.rank[pv]+=1
        
        dsu=DSU(n)
        q1=[]
        for i,q in enumerate(queries):
            u=q[0]
            v=q[1]
            l=q[2]
            idx=i
            q1.append([l,u,v,idx])
        
        q1.sort(key=lambda x:x[0])
        edges.sort(key=lambda x:x[2])
        j=0
        ans=[False]*(len(queries))
        for q in q1:
            limit=q[0]
            u=q[1]
            v=q[2]
            idx=q[3]
            while j<len(edges) and edges[j][2]<limit:
                e=edges[j]
                u1=e[0]
                v1=e[1]
                l=e[2]
                
                
                if dsu.find_parent(u1)!=dsu.find_parent(v1):
                        dsu.unite(u1,v1)
                
                j+=1
            if dsu.find_parent(u)==dsu.find_parent(v):
                ans[idx]=True
            
        return ans

                    
            




            
            

        