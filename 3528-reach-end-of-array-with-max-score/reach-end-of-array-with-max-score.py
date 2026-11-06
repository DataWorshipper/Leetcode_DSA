class Solution:
    def findMaximumScore(self, nums: List[int]) -> int:
        n=len(nums)
        nge=[n]*n
        st=[]
        for i in range(n-1,-1,-1):
            while len(st)>0 and nums[st[-1]]<=nums[i]:
                st.pop()
            if len(st)>0:
                nge[i]=st[-1]
            st.append(i)
           
        i=0
        sc=0
        while nge[i]!=n:
            sc+=(nge[i]-i)*nums[i]
            i=nge[i]
        sc+=(n-1-i)*nums[i]
        return sc
