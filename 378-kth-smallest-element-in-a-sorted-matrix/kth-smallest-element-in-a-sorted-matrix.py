class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        def count(x:int)->bool:
            n=len(matrix)
            cnt=0
            for i in range(n):
                arr=matrix[i]
                idx=bisect_right(arr,x)
                cnt+=idx
            
            return cnt>=k
        
        low=-10**9
        high=10**9
        ans=low
        while low<=high:
            mid=low+(high-low)//2
            if count(mid)==True:
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans


