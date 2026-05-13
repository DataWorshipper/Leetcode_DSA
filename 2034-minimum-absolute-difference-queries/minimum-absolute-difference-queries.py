class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        res=[]
        mpp=defaultdict(list)
        for i,x in enumerate(nums):
            mpp[x].append(i)
        
        for q in queries:
            l=q[0]
            r=q[1]
            arr=[]
            for key,array in mpp.items():
                idx=bisect_left(array,l)
                if idx<len(array) and array[idx]<=r:
                    arr.append(key)
                
            arr.sort()
            m=float('inf')
            for i in range(len(arr)-1):
                m=min(m,arr[i+1]-arr[i])
            if m==float('inf'):
                res.append(-1)
            else:
                res.append(m)
        
        return res



        