class Solution:
   def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        n=len(nums)
        pref=[0]*n
        pref[0]=nums[0]
        for i in range(1,n):
            pref[i]=pref[i-1]+nums[i]
        def check(length):
            l=0
            r=0
            while r<n:
                while r-l+1>length:
                    l+=1
                
                if r-l+1==length:
                    mid=(r+l)//2
                    median=nums[mid]
                    c1=0
                    c2=pref[r]-pref[mid]
                    if l>0:
                        c1=pref[mid]-pref[l-1]
                    else:
                        c1=pref[mid]
                    cost=(mid-l+1)*median-c1+c2-(r-mid)*median
                    if cost<=k:
                        return True
                    
                r+=1
            return False
        
                    
        lo=1
        hi=n
        ans=1
        while lo<=hi:
            mid=lo+(hi-lo)//2
            if check(mid):
                ans=mid
                lo=mid+1
            else:
                hi=mid-1
        return ans
        