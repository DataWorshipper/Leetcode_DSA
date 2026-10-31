class Solution:
    def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
        m=len(dungeon)
        n=len(dungeon[0])
        dp=defaultdict(int)
        INF=float("inf")
        def f(i,j):
            if i==m-1 and j==n-1:
                return max(1,1-dungeon[m-1][n-1])
            if (i,j) in dp:
                return dp[(i,j)]
            a=INF
            b=INF
            ans=INF
            if i+1<m:
                a=f(i+1,j)
            if j+1<n:
                b=f(i,j+1)
            ans=max(1,min(a,b)-dungeon[i][j])
            dp[(i,j)]=ans
            return ans
        
        return f(0,0)
        


        