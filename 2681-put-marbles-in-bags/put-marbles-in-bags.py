class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n=len(weights)
        wt0=weights[0]
        wtn=weights[n-1]
        ans=wt0+wtn
        arr=[]
        for i in range(n-1):
            arr.append(weights[i]+weights[i+1])
        arr.sort()
        t=k-1
        s_l=0
        s_h=0
        sz=len(arr)
        for i in range(t):
            s_l+=arr[i]
        
        for i in range(sz-1,sz-k,-1):
            s_h+=arr[i]
        
        return s_h-s_l


        