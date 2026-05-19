class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def count(x:int):
            cnt=0
            for i in range(m):
                mul=i+1
                beg=mul
                end=(i+1)*n
                max_idx=x//mul
                cnt+=min(max_idx,n)
            
            return cnt>=k
        
        low=1
        high=m*n
        ans=low
        while low<=high:
            mid=low+(high-low)//2
            if count(mid)==True:
                ans=mid
                high=mid-1
            else:
                low=mid+1
        
        return ans



        