class Solution:
    def minCost(self, grid: list[list[int]], k: int) -> int:
        m=len(grid)
        n=len(grid[0])
        
        if m==1 and n==1:
            return grid[0][0]
        pq=[]
        heapq.heappush(pq,(grid[0][0],0,0,0,0))
        dist=defaultdict(int)
        nx=[1,-1,0,0]
        ny=[0,0,1,-1]
        dist[(0,0,0,0)]=grid[0][0]

        while pq:
            distance,x,y,turns,prev_d=heapq.heappop(pq)

            for i in range(4):
                new_x=x+nx[i]
                new_y=y+ny[i]

                if new_x<0 or new_x>=m or new_y<0 or new_y>=n:
                    continue

                new_turn=turns
                new_d=0

                if new_x==x and new_y<y:
                    new_d=4
                if new_x==x and new_y>y:
                    new_d=3
                if new_x<x and new_y==y:
                    new_d=2
                if new_x>x and new_y==y:
                    new_d=1

                if prev_d != 0 and new_d != prev_d:
                    new_turn += 1

                if new_turn>k:
                    continue

                new_dist=distance+grid[new_x][new_y]
                state=(new_x,new_y,new_turn,new_d)

                if state not in dist or new_dist<dist[state]:
                    dist[state]=new_dist
                    heapq.heappush(pq,(new_dist,new_x,new_y,new_turn,new_d))

        mn=float("inf")

        for turn in range(k+1):
            for d in range(1,5):
                if (m-1,n-1,turn,d) in dist:
                    mn=min(mn,dist[(m-1,n-1,turn,d)])

        return -1 if mn==float("inf") else mn