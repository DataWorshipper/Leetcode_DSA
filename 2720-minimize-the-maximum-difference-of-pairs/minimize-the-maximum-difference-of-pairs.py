class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        def count(diff:int)->bool:
            n=len(nums)
            cnt=0
            i=0
            while i<n-1:
                m=nums[i+1]-nums[i]
                
                if m<=diff:
                    cnt+=1
                    i+=2
                else:
                    i+=1
                
            return cnt>=p
        
        nums.sort()
        n=len(nums)
        low=0
        
        high=nums[-1]-nums[0]
        ans=low
        while low<=high:
            mid=low+(high-low)//2
            if count(mid):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        
        return ans




        