class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n=len(nums)
        for i in range(n-1):
            if nums[i]==nums[i+1]:
                nums[i]=nums[i]*2
                nums[i+1]=0
        
        pos=[]
        zero=[]
        for i in range(n):
            if nums[i]>0:
                pos.append(nums[i])
            else:
                zero.append(nums[i])
        
        pos.extend(zero)
        return pos

