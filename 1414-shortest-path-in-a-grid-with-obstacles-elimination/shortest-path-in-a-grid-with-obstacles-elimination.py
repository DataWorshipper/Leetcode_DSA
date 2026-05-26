class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        
        m=len(grid)
        n=len(grid[0])

        INF=float('inf')

        dist=[[INF]*n for _ in range(m)]

        q=deque()

        dist[0][0]=0

        q.append((0,0,0,0))

        vis=set()
        vis.add((0,0,0))

        dirn=[(1,0),(0,1),(-1,0),(0,-1)]

        ans=float('inf')

        while q:

            x,y,d,obstacle=q.popleft()

            if x==m-1 and y==n-1:

                if obstacle<=k:
                    ans=min(ans,d)

                continue

            for i in range(4):

                new_x=x+dirn[i][0]
                new_y=y+dirn[i][1]

                if new_x>=0 and new_x<m and new_y>=0 and new_y<n:

                    if grid[new_x][new_y]==0:

                        state=(new_x,new_y,obstacle)

                        if d+1<dist[new_x][new_y] or state not in vis:

                            dist[new_x][new_y]=d+1

                            vis.add(state)

                            q.append((new_x,new_y,d+1,obstacle))

                    else:

                        state=(new_x,new_y,obstacle+1)

                        if obstacle+1<=k and (d+1<dist[new_x][new_y] or state not in vis):

                            dist[new_x][new_y]=d+1

                            vis.add(state)

                            q.append((new_x,new_y,d+1,obstacle+1))

        if ans==float('inf'):
            return -1

        return ans