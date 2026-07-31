class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def check(mx):
            cnt=0
            prev=0
            for i in range(len(nums)):
                if nums[i]<=mx:
                    if prev==0:
                        cnt+=1
                        prev=1
                    else:
                        prev=0
                else:
                    prev=0
            return cnt>=k
                    
                

        lo=1
        hi=10**9
        ans=-1
        while lo<=hi:
            mid=lo+(hi-lo)//2
            if check(mid):
                ans=mid
                hi=mid-1
            else:
                lo=mid+1
        return ans


        