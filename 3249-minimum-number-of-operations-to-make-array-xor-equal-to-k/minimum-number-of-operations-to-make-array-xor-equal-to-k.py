class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        mpp=defaultdict(int)
        n=len(nums)
        for i in range(n):
            val=nums[i]
            for bit in range(21):
                b=(val>>bit)&1
                if b==1:
                    mpp[bit]+=1
        ans=0
        for bit in  range(21):
            b=(k>>bit)&1
            parity=mpp[bit]%2
            if parity!=b:
                ans+=1
        return ans


        