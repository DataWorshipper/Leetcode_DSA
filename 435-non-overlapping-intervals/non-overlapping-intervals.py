class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        n=len(intervals)
        if n==1:
            return 0
        intervals.sort()
        start=intervals[0][0]
        end=intervals[0][1]
        i=1
        cnt=0
        while i<n:
            if intervals[i][0]<end:
               cnt+=1
               end=min(end,intervals[i][1])
                
            else:
                end=intervals[i][1]
            i+=1
        return cnt

        