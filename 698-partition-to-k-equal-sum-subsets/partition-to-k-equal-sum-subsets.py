class Solution:
    def canPartitionKSubsets(self, nums: list[int], k: int) -> bool:
        s=sum(nums)
        n=len(nums)
        if s%k!=0:
            return False
        target=s//k
        slots=[0]*k
        nums.sort(reverse=True)
        def solve(i):
            if i==n:
                return True
            val=nums[i]
            for j in range(k):
                if slots[j]+val>target:
                    continue
                if j>0 and slots[j]==slots[j-1]:
                    continue
                slots[j]+=val
                if solve(i+1):
                    return True
                slots[j]-=val
            return False
                    
        return solve(0)

            
        