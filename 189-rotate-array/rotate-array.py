class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        n=len(nums)
        arr=[]
        k=k%n
        arr2=[]
        for i in range(n-k,n):
            arr.append(nums[i])
        
        for i in range(n-k):
            arr2.append(nums[i])

        nums[k:]=arr2
        
        nums[0:k]=arr

        
        
        

        

        
        