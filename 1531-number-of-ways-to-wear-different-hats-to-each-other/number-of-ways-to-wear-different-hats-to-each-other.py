class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        dp=defaultdict(int)
        n=len(hats)
        MOD=10**9+7
        def ways(index,mask,mpp,n):
            if mask==(1<<n)-1:
                return 1
            if index>40:
                return 0
            if (index,mask) in dp:
                return dp[(index,mask)]
            ans=0
            ans=(ans+ways(index+1,mask,mpp,n))%MOD
            for person in mpp[index]:
                if (mask&(1<<person)==0):
                    ans=(ans+ways(index+1,mask|(1<<person),mpp,n))%MOD
            
            dp[(index,mask)]=ans%MOD
            return ans%MOD


        mpp=defaultdict(list)
      
        for i in range(n):
            person=i
            for j in range(len(hats[person])):
                mpp[hats[person][j]].append(person)
        
        return ways(0,0,mpp,n)%MOD
        


        