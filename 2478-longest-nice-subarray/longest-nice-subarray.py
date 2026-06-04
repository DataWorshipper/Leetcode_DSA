class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans=1
        n=len(nums)
        for i in range(n):
            val=nums[i]
            st=set()
            length=0
            flag=True
            for j in range(i,n):
                for k in range(31):
                    bit=(nums[j]>>k)&1
                    if bit==1:
                        if k not in st:
                            st.add(k)
                        else:
                            flag=False
                            break
                if flag:
                    length+=1
                else:
                    break
            ans=max(ans,length)
        return ans
                
                
        