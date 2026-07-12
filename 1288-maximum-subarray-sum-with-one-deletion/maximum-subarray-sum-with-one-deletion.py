class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n=len(arr)
        pref=[0]*n
        suff=[0]*n
        if max(arr) < 0:
            return max(arr)
        pref[0]=max(0,arr[0])
        suff[n-1]=max(0,arr[n-1])
        for i in range(1,n):
            pref[i]=max(pref[i-1]+arr[i],arr[i])
        for i in range(n-2,-1,-1):
            suff[i]=max(arr[i],suff[i+1]+arr[i])
        
        mx=-float("inf")
        for i in range(n):
            mx=max(mx,pref[i])
            mx=max(mx,suff[i])
        
        for i in range(1,n-1):
            mx=max(mx,pref[i-1]+suff[i+1])
        
        return mx
        