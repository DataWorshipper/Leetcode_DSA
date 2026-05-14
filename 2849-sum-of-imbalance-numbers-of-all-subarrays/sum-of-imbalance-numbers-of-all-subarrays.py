class Solution:
    def sumImbalanceNumbers(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        for l in range(n):
            s=set()
            curr=0
            for r in range(l,n):
                x=nums[r]
                
                if x not in s:
                    if len(s)>0:
                        if x-1 in s and x+1 in s:
                            curr-=1
                        elif x-1 not in s and x+1 not in s:
                            curr+=1
                s.add(x)
                ans+=curr
        return ans
                    
        