class Solution:
    def intervalIntersection(self, firstList: list[list[int]], secondList: list[list[int]]) -> list[list[int]]:
        
        n=len(firstList)
        m=len(secondList)
        i=0
        j=0
        arr=[]
        while i<n and j<m:
            a,b=firstList[i][0],firstList[i][1]
            c,d=secondList[j][0],secondList[j][1]
            l=max(a,c)
            r=min(b,d)
            if l<=r:
                arr.append((l,r))
            if b<d:
                i+=1
            elif b>d:
                j+=1
            else:
                i+=1
                j+=1
        return arr
