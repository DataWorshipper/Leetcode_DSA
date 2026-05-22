class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        class DSU():
            def __init__(self,n):
                self.n=n
                self.parent=[0]*(n+1)
                self.rank=[0]*(n+1)
                self.size=[1]*(n+1)
                for i in range(n+1):
                    self.parent[i]=i
            def find_parent(self,x):
                if self.parent[x]==x:
                    return x
                self.parent[x]=self.find_parent(self.parent[x])
                return self.parent[x]
            
            def unite(self,x,y):
                px=self.find_parent(x)
                py=self.find_parent(y)
                sx=self.size[x]
                
                sy=self.size[y]
                if px==py:
                    return
                else:
                    if self.rank[px]<self.rank[py]:
                        self.parent[px]=self.parent[py]
                        self.size[py]+=self.size[px]
                    elif self.rank[px]>self.rank[py]:
                        self.parent[py]=self.parent[px]
                        self.size[px]+=self.size[py]
                    else:
                        self. parent[py]=self.parent[px]
                        self.size[px]+=self.size[py]
                        self.rank[px]+=1
        
        
        n=len(edges)
        dsu=DSU(n)
        ans=[0]*2
        for u,v in edges:
            if dsu.find_parent(u)!=dsu.find_parent(v):
                dsu.unite(u,v)
            else:
                ans[0]=u
                ans[1]=v
            
        return ans





                