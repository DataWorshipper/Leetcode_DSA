class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        n=len(matrix)
        m=len(matrix[0])
        pref=[[0]*m for _ in range(n)]
        for i in range(m):
            pref[0][i]=matrix[0][i]
        
        for i in range(1,n):
            for j in range(m):
                pref[i][j]=pref[i-1][j]+matrix[i][j]

        def f(arr:List,target:int)->int:
            n=len(arr)
            prefix=[0]*n
            prefix[0]=arr[0]
            for i in range(1,n):
                prefix[i]=prefix[i-1]+arr[i]

            mpp=defaultdict(int)
            ans=0
            mpp[0]=1
            for i in range(n):
                
                need=prefix[i]-target
                if need in mpp:
                    ans+=mpp[need]
                mpp[prefix[i]]+=1
               
            return ans
        cnt=0
        for i in range(n):
            for j in range(i,n):
                r1=i
                r2=j
                col=[0]*m
                for c in range(m):
                    if i>=1:
                        col[c]=pref[j][c]-pref[i-1][c]
                    else:
                        col[c]=pref[j][c]
                cnt+=f(col,target)
        
        return cnt
                


        