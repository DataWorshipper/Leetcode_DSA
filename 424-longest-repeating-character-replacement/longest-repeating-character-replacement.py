class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mpp=defaultdict(int)
        l=0
        r=0
        n=len(s)
        def check(sz):
            mpp=defaultdict(int)
            l=0
            r=0
            ans=float("inf")
            while r<n:
                mpp[ord(s[r])-ord('A')]+=1
                while r-l+1>sz:
                    mpp[ord(s[l])-ord('A')]-=1
                    l+=1
                if r-l+1==sz:
                    mx=0
                    for i in range(26):
                        mx=max(mx,mpp[i])
                    ans=min(ans,sz-mx)
                r+=1
            return ans
        low=1
        high=n
        ans=1
        while low<=high:
            mid=low+(high-low)//2
            if check(mid)<=k:
                ans=mid
                low=mid+1
            else:
                high=mid-1
        return ans

                    
                
                    

        