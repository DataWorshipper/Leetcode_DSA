class Solution:
    def findMaxSum(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        arr=[(q,i) for i,q in enumerate(nums1)]
        arr.sort()  
        pq=[]
        n=len(nums1)
        ans=[0]*len(nums1)
        ans[arr[0][1]]=0
        i=1
        j=0
        s=0
        while i<n:
            while j<i and arr[j][0]<arr[i][0]:
                heapq.heappush(pq,nums2[arr[j][1]])
                s+=nums2[arr[j][1]]
                while len(pq)>k:
                    s-=pq[0]
                    heapq.heappop(pq)
                    
                j+=1
            ans[arr[i][1]]=s
            i+=1
          
        return ans
            

