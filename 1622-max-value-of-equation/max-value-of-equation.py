class Solution:
    def findMaxValueOfEquation(self, points: list[list[int]], k: int) -> int:
        
        n=len(points)
        pq=[]
        heapq.heappush(pq,(-points[0][1]+points[0][0],points[0][0]))
        ans=-float("inf")
        for j in range(1,n):
            x=points[j][0]
            y=points[j][1]
            while pq and abs(x-pq[0][1])>k:
                heapq.heappop(pq)
            if pq:
                ans=max(ans,x+y-pq[0][0])
            heapq.heappush(pq,(-points[j][1]+points[j][0],points[j][0]))
        return ans
            
            