class Solution:
    def minCost(self, nums: List[int], k: int) -> int:
        mpp1=defaultdict(int)
        n=len(nums)
        for l in range(n):
            mpp=defaultdict(int)
            length=0
            for r in range(l,n):
                mpp[nums[r]]+=1
                if mpp[nums[r]]==1:
                    mpp1[(l,r)]=length
                elif mpp[nums[r]]==2:
                    mpp1[(l,r)]=length+2
                    length+=2
                else:
                    mpp1[(l,r)]=length+1
                    length+=1
        
        INF=float('inf')
        dp=[INF]*n
        dp[0]=k
        for  i in range(1,n):
            for j in range(0,i):
                dp[i]=min(dp[j]+mpp1[(j+1,i)]+k,dp[i],mpp1[(0,i)]+k)
        
        return dp[n-1]


               
                
                

        




        