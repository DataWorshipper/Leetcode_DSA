class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        n=len(fruits)
        l=0
        r=0
        mpp=defaultdict(int)
        ans=-float("inf")
        while r<n:
            mpp[fruits[r]]+=1
            while len(mpp)>2:
                mpp[fruits[l]]-=1
                if mpp[fruits[l]] == 0:
                    del mpp[fruits[l]]
                l+=1
            if len(mpp)<=2:
                ans=max(ans,r-l+1)
            r+=1
        return ans





        