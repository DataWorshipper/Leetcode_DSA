class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        n=len(grid)
        nx=[1,-1,0,0]
        ny=[0,0,1,-1]
        def bfs(t):
            vis=[[0]*n for _ in range(n)]
            if grid[0][0]>t:
                return False
            q=deque()
            q.append((0,0))
            vis[0][0]=1
            while q:
                x,y=q.popleft()
                if x==n-1 and y==n-1:
                    return True
                for i in range(4):
                    new_x=x+nx[i]
                    new_y=y+ny[i]
                    if new_x>=0 and new_x<n and new_y>=0 and new_y<n:
                        if vis[new_x][new_y]==0 and grid[new_x][new_y]<=t:
                            vis[new_x][new_y]=1
                            q.append((new_x,new_y))
            return False
            
                    
        low=0
        high=n*n
        ans=0
        while low<=high:
            mid=low+(high-low)//2
            if bfs(mid)==True:
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans
