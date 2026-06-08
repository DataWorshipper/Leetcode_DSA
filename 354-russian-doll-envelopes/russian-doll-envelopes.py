class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        def lis(arr):
            temp=[]
            n=len(arr)
            temp.append(arr[0])
            for i in range(1,n):
                if arr[i]>temp[-1]:
                    temp.append(arr[i])
                else:
                    idx=bisect.bisect_left(temp,arr[i])

                    temp[idx]=arr[i]
            return len(temp)
        
        envelopes.sort(key=lambda x:(x[0],-x[1]))
        h=[]
        for i in range(len(envelopes)):
            h.append(envelopes[i][1])
        return lis(h)
        