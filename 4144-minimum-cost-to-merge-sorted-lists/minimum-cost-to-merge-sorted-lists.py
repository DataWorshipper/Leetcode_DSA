class Solution:
    def minMergeCost(self, lists: List[List[int]]) -> int:
        n=len(lists)
        length=defaultdict(int)
        median=defaultdict(int)
        for mask in range(1<<n):
            if mask==0:
                continue
            la=0
            lb=[]
            for j in range(n):
                if mask&(1<<j):
                    la+=len(lists[j])
                    for el in lists[j]:
                        lb.append(el)
            
            lb.sort()
            length[mask]=la
            if len(lb)%2==1:
                median[mask]=lb[len(lb)//2]
            else:
                median[mask]=lb[(len(lb)//2)-1]
        INF=float("inf")
        dp=[INF]*(1<<n)
        dp[0]=0
        for i in range(n):
            dp[1 << i] = 0
        for mask in range(1<<n):
            if mask==0:
                continue
            sub =mask
            while sub:
                dp[mask]=min(dp[mask],dp[sub]+dp[mask^sub]+length[sub]+length[mask^sub]+abs(median[sub]-median[sub^mask]))
                sub=(sub-1)&mask
        return dp[(1<<n)-1]

        



                    

        