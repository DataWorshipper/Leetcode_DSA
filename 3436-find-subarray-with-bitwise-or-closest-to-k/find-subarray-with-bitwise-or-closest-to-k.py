class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        gl=set()
        curr=set()
        curr.add(nums[0])
        for i in range(1,len(nums)):
            for e in curr:
                gl.add(e)
            
            nxt=set()
            nxt.add(nums[i])
            for e in curr:
                nxt.add(e|nums[i])
            
            curr=nxt
        
        for e in curr:
            gl.add(e)
        ans=float('inf')
        for e in gl:
            ans=min(ans,abs(k-e))
        
        return ans

        