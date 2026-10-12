class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        n=len(nums)
        cnt=defaultdict(int)
        mx=max(nums)
        freq=Counter(nums)
        for i in range(1,mx+1):
            for j in range(i,mx+1,i):
                cnt[i]+=freq[j]
        exact=[0]*(mx+1)
        for i in range(mx,0,-1):
            exact[i]=cnt[i]*(cnt[i]-1)//2
            for j in range(2*i,mx+1,i):
                exact[i]-=exact[j]
        pref = [0] * (mx + 1)
        for i in range(1, mx + 1):
            pref[i] = pref[i - 1] + exact[i]
        def check(q):
            low=1
            high=mx
            ans=1
            while low<=high:
                mid=low+(high-low)//2
                if pref[mid]>q:
                    ans=mid
                    high=mid-1
                else:
                    low=mid+1
            return ans


        ans=[]
        for q in queries:
            ans.append(check(q))
        return ans

                    




        