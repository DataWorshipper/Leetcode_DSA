class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        n=len(nums)
        prefix=[0]*n
        prefix[0]=nums[0]
        for i in range(1,n):
            prefix[i]=prefix[i-1]^nums[i]
        mpp=defaultdict(int)
        cnt=0
        for x in prefix:
            if x==0:
                cnt+=1
            if x in mpp:
                cnt+=mpp[x]
            
            mpp[x]+=1
        return cnt

        

        