class Solution:
    def smallestStringWithSwaps(self, s: str, edges: List[List[int]]) -> str:
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
                        self.parent[pv]=self.parent[pu]
                    elif ru<rv:
                        self.parent[pu]=self.parent[pv]
                    else:
                        self.parent[pu]=self.parent[pv]
                        self.rank[pv]+=1
        
        n=len(s)
        dsu=DSU(n)
        for u,v in edges:
            if dsu.find_parent(u)!=dsu.find_parent(v):
                dsu.unite(u,v)
            
        

        arr=[dsu.find_parent(i) for i in range(n)]
        mpp=defaultdict(list)
        for i in range(n):
            mpp[arr[i]].append((s[i],i))
        
        for key,_ in mpp.items():
            mpp[key].sort(reverse=True)
        
        s1=""
        for i in range(n):
            
            up=arr[i]
            ch,idx=mpp[up].pop()
            s1+=ch
            if len(mpp[up])==0:
                del mpp[up]
        
        return s1
            


        




        