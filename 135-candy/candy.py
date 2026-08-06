class Solution:
    def candy(self, ratings: List[int]) -> int:
        n=len(ratings)
        choc1=[1]*n
        choc2=[1]*n
        for i in range(1,n):
            if ratings[i]>ratings[i-1]:
                choc1[i]=choc1[i-1]+1
        for i in range(n-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                choc2[i]=choc2[i+1]+1
        ans=0
        for i in range(n):
            ans+=(max(choc1[i],choc2[i]))
        return ans        