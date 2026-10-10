class Solution:
    def countGood(self, nums: list[int], k: int) -> int:
        mpp=defaultdict(int)
        n=len(nums)
        l=0
        r=0
        s1=0
        cnt=0
        while r<n:
            s1+=mpp[nums[r]]
            mpp[nums[r]]+=1
            while s1>=k:
                mpp[nums[l]]-=1
                s1-=mpp[nums[l]]
                l+=1
            cnt+=(r-l+1)
            
            
            r+=1
        
        return n*(n+1)//2 -cnt
           

        