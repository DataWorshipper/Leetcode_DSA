class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        n=len(nums)
        def nse():
            nse_arr=[n]*n
            st=[]
            for i in range(n-1,-1,-1):
                while len(st)!=0 and nums[st[-1]]>nums[i]:
                    st.pop()
                if len(st)>0:
                    nse_arr[i]=st[-1]
                st.append(i)
            return nse_arr
        def pse():
            pse_arr=[-1]*n
            st=[]
            for i in range(n):
                while len(st)!=0 and nums[st[-1]]>=nums[i]:
                    st.pop()
                if len(st)>0:
                    pse_arr[i]=st[-1]
                st.append(i)
            return pse_arr
        nse_arr=nse()
        pse_arr=pse()
        for i in range(n):
            nse_id=nse_arr[i]
            pse_id=pse_arr[i]
            length=nse_id-pse_id-1
            if nums[i]*(length)>threshold:
                return length
        return -1





        