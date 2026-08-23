class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        m=destination[0]
        n=destination[1]
        s=""
        def ways(r,c):
            nonlocal k,s
        
            if r==m and c==n:
                return
            way=math.comb(m-r+n-c-1,m-r)
            if k<=way:
                s+='H'
                ways(r,c+1)
            else:
                s+='V'
                k-=way
                ways(r+1,c)
        ways(0,0)
        return s
            
        
        
        


        