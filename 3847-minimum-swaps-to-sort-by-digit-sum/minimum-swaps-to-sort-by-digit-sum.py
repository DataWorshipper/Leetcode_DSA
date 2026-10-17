class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(x):
            s=str(x)
            sum=0
            for i in range(len(s)):
                sum+=int(s[i])
            return sum
        mpp=defaultdict(int)
        for i in range(len(nums)):
            mpp[nums[i]]=i
        nums.sort(key=lambda x:(digit_sum(x),x))
        n=len(nums)
        vis=[0]*n
        swaps=0
        for i in range(n):
            if vis[i]==1 or mpp[nums[i]]==i:
                continue
            j=i
            cyclelen=0
            while vis[j]==0:
                vis[j]=1
                j=mpp[nums[j]]
                cyclelen+=1
            if cyclelen>0:
                swaps+=(cyclelen-1)
        return swaps

        