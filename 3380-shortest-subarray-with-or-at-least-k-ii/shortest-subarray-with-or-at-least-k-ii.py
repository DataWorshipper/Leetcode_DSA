class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        cnt=[0]*32
        l=0
        r=0
        n=len(nums)
        def check(cnt,k):
            ans=0
            for i in range(32):
                if cnt[i]>0:
                    ans+=(1<<i)
            return ans>=k
        ans=float('inf')
        while r<n:
            for i in range(32):
                bit=(nums[r]>>i)&1
                if bit==1:
                    cnt[i]+=1
            
            while  l<=r and check(cnt,k)==True:
                ans=min(ans,r-l+1)
                for i in range(32):
                    bit=(nums[l]>>i)&1
                    if bit==1:
                        cnt[i]-=1
                
                l+=1
            
            r+=1
        if ans==float('inf'):
            return -1
        return ans


        