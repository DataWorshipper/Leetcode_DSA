class Solution:
    def maxPoints(self, technique1: List[int], technique2: List[int], k: int) -> int:
        n=len(technique1)
        cnt=0
        marked=[0]*n
        s1=0
        for i in range(n):
            if technique1[i]>=technique2[i]:
                cnt+=1
                marked[i]=1
                s1+=technique1[i]
        if cnt>=k:
            s2=0
            for i in range(n):
                if marked[i]==0:
                    s2+=technique2[i]
            return s1+s2
        else:
            req=k-cnt
            pq=[]
            for i in range(n):
                if marked[i]==0:
                    heapq.heappush(pq,(-technique2[i]+technique1[i],i))
                    if len(pq)>req:
                        heapq.heappop(pq)
            while pq:
                diff,index=heapq.heappop(pq)
                marked[index]=1
            s1=0
            s2=0
            for i in range(n):
                if marked[i]==1:
                    s1+=technique1[i]
                else:
                    s2+=technique2[i]
            return s1+s2
        return -1


            
            

        

        