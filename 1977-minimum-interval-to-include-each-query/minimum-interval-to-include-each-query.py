class Solution:
    def minInterval(self, intervals: list[list[int]], queries: list[int]) -> list[int]:
        intervals.sort()
        pq=[]
        j=0
        arr=[]
        for i,q in enumerate(queries):
            arr.append((q,i))
        arr.sort()
        ans=[0]*(len(queries))
        for q,i in arr:
            
            while j<len(intervals) and intervals[j][0]<=q:
                l=intervals[j][0]
                r=intervals[j][1]
                heapq.heappush(pq,(r-l+1,r))
               
                j+=1
            while len(pq)>0 and pq[0][1]<q:
                heapq.heappop(pq)
            if pq:
                ans[i]=pq[0][0]
            else:
                ans[i]=-1
        return ans
                
                
