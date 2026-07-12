class Solution:
    def minimumCost(self, nums: list[int], k: int) -> int:
        
        n=len(nums)
        cnt=0
        res=k
        s=0
        MOD=10**9+7
        for i in range(n):
            if nums[i]<res:
                res-=nums[i]
            
            else:
                diff=nums[i]-res
                need=(diff+k-1)//k
                res+=(need*k)
                sum1=((cnt+need)*(cnt+need+1)//2)%MOD
                sum2=((cnt)*(cnt+1)//2)%MOD
                cnt+=need
                s+=(sum1-sum2)
                res-=nums[i]
        return s%MOD
                
        