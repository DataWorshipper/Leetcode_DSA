class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        arr=[]
        n=len(nums1)
        for i in range(n):
            arr.append((nums2[i],nums1[i]))
        arr.sort(reverse=True)
        pq=[]
        s=0
        mx=-float('inf')
        for i in range(n):
            heapq.heappush(pq,arr[i][1])
            s+=arr[i][1]
            
            while len(pq)>k:
                val=heapq.heappop(pq)
                s-=(val)
            if len(pq)==k:
                mx=max(mx,s*arr[i][0])
        return mx
            
            
