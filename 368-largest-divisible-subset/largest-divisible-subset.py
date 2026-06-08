class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n=len(nums)
        nums.sort()
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[i]%nums[j]==0:
                    dp[i]=max(dp[i],1+dp[j])
        
        l=max(dp)
        ans=[]
        idx=0
        for i in range(n):
            if dp[i]==l:
                idx=i
        ans.append(nums[idx])
        while l!=1:
            
            for j in range(idx-1,-1,-1):
                if dp[j]==(l-1) and nums[idx]%nums[j]==0:
                    ans.append(nums[j])
                    idx=j
                    l-=1
                    break
                    
        
        ans.reverse()
        return ans
                




        