class Solution:
    def longestAlternating(self, nums: List[int]) -> int:
        n=len(nums)
        left=[[1]*2 for _ in range(n)]
        right=[[1]*2 for _ in range(n)]
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                left[i][0]=left[i-1][1]+1
            elif nums[i]<nums[i-1]:
                left[i][1]=left[i-1][0]+1
        for i in range(n-2,-1,-1):
            if nums[i]>nums[i+1]:
                right[i][0]=right[i+1][1]+1
            elif nums[i]<nums[i+1]:
                right[i][1]=right[i+1][0]+1
        
        mx=-float("inf")
        for i in range(n):
            mx=max(mx,left[i][0],left[i][1])
        for i in range(n):
            mx=max(mx,right[i][0],right[i][1])
        
        for i in range(1,n-1):
            if nums[i-1]<nums[i+1]:
                mx=max(mx,left[i-1][1]+right[i+1][0])
            elif nums[i-1]>nums[i+1]:
                mx=max(mx,left[i-1][0]+right[i+1][1])
        return mx
        


            
        