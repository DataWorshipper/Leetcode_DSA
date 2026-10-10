class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        n=len(nums)
        s=sum(nums)
        target=s-x
        if target == 0:
            return n
        l=0
        r=0
        s1=0
        ans=0
        while r<n:
            s1+=nums[r]
            while  l<=r and s1>target:
                s1-=nums[l]
                l+=1
            if s1==target:
                ans=max(ans,r-l+1)
            r+=1
        if ans==0:
            return -1
        else:
            return n-ans
            



        