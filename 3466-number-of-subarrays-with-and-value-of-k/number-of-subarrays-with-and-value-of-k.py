class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        
        n=len(nums)
        def check(cnt,k,n,l,r):
            ans=0
            for i in range(31):
                if cnt[i]==(r-l+1):
                    ans+=(1<<i)
            
            return ans<k
        
        def find_ans(x):
            l=0
            r=0
            ans=0
            cnt=[0]*31
            while r<n:
                for i in range(31):
                    bit=(nums[r]>>i)&1
                    if bit==1:
                        cnt[i]+=1
                
                while l<=r and  check(cnt,x,n,l,r):
                    
                    for i in range(31):
                        bit=(nums[l]>>i)&1
                        if bit==1:
                            cnt[i]-=1
                    l+=1
                ans+=(r-l+1)
                r+=1
            return ans
        
        return find_ans(k)-find_ans(k+1)

            
                    


