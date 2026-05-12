class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n=len(nums)
        diff=[0]*n
        
        for i in range(n):
            diff[i]=nums[i]-i
        
        cnt=Counter(diff)
        ans=n*(n-1)//2
        count=0

        for key,val in cnt.items():
            if cnt[key]>1:
                count+=(val*(val-1)//2)
        
        return ans-count
            


        